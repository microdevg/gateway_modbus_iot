#include "flash_mem.h"
#include "nvs.h"
#include "nvs_flash.h"
#include <stdio.h>


static nvs_handle_t my_handle;

/**Estado de inicializacion del la memoria */
static int flash_inited = 0;



nvs_handle_t* get_phandle(){

    return &my_handle;
}

esp_err_t flash_mem_init(){
    esp_err_t err = nvs_flash_init();
    err = nvs_open(PARTITION_NAME, NVS_READWRITE, &my_handle);
    (err != ESP_OK)?
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err))
        :printf("Inicializado correctamente\n");
    
    flash_inited = 1;
    return err;
}


esp_err_t flash_mem_save(char* id,char* pass){
    if(flash_inited == 0)flash_mem_init();
    esp_err_t err = nvs_set_str(my_handle, SSID_KEY, id);
    // Guardo ID
    (err != ESP_OK)? 
                    printf("Failed to save SSID!\n")
                    :printf("SSID guardado correctamente\n");
    // Guardar Contraseña
    err = nvs_set_str(my_handle, PASSWORD_KEY, pass);
    (err != ESP_OK)? 
                    printf("Failed to save PASS!\n")
                    :printf("PASS guardado correctamente\n");
    // Confirmar cambios, si esto no se almacena en flash.
    err = nvs_commit(my_handle);
    (err != ESP_OK)?
                printf("Failed to commit NVS updates!\n")
                :printf("guardado correctamente2");
    
    nvs_close(my_handle);
    flash_inited = 0;
    return err;
}


esp_err_t flash_mem_get(char* id, char* pass){
    if(flash_inited == 0)flash_mem_init();
    esp_err_t err = nvs_open("storage", NVS_READONLY, &my_handle);
    if (err != ESP_OK)
    {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }
    // Leer SSID
    size_t ssid_size =0;
    // Primero con parametro id en NULL, se lee el size del string
    err = nvs_get_str(my_handle, SSID_KEY, NULL, &ssid_size);
    // Luego se lee el string
    err = nvs_get_str(my_handle, SSID_KEY, id, &ssid_size);

    if (err != ESP_OK)
    {
        printf("Failed to read SSID!\n");
        return err;
    }

    // Leer Contraseña
    size_t pass_size = 0;
    err = nvs_get_str(my_handle, PASSWORD_KEY, NULL, &pass_size);
    err = nvs_get_str(my_handle, PASSWORD_KEY, pass, &pass_size);
    if (err != ESP_OK)
    {
        printf("Failed to read Password!\n");
        return err;
    }
    printf("NVS leída correctamente SSID:%s  password:%s", id, pass);
    nvs_close(my_handle);
    flash_inited = 0;
    return err;
}



esp_err_t flash_memory_clear_credentials(){
    if(flash_inited == 0)flash_mem_init();
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }
    nvs_erase_all(&my_handle);
    err = nvs_erase_key(&my_handle,SSID_KEY );
    err = nvs_erase_key(&my_handle,PASSWORD_KEY );
     // Confirmar cambios
    err = nvs_commit(my_handle);
    nvs_close(my_handle);
    return err;
}

//Sin implementar aun
esp_err_t flash_mem_deinit(){
 flash_inited = 0;
 nvs_close(my_handle);
 return ESP_OK;
}