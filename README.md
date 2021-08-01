# Actividad 3

Implementar mediante el modelo de Máquina de Estados Finitos el antirrebote de teclas y la lógica de funcionamiento de un semáforo.

## Descripción

Utiliza la lectura de las tecla 2 para cambiar el estado del semáforo.
En la siguiente tabla se muestan los estados

| ESTADO       | Resultado                                 |
| ------------ | ----------------------------------------- |
| Normal       | ROJO - ROJO + AMARILLO - VERDE - AMARILLO |
| Alarma       | ROJO INTERMITENTE                         |
| Desconectado | AMARILLO INTERMITENTE                     |


## Dependencias

* Utiliza la librería sapi.h de firmware v3

El firmware tiene 4 capas implementadas mediante 5 archivos .h y .c.

Las capas, en orden decremental son:
* Main
* Semaforo 
* Teclas / Secuencia
* Led

### Main
Es la capa de la aplicación que se ejecuta. En esta solo se utiliza la funciones de Semáforo

### Semáforo
Es la capa donde se cambian a los distintos modos de semáfro. En esta utiliza los servicios de Tecla y Secuencia
### Teclas
Esta capa interpreta, si se le consulta, si se presiono o solto una tecla.
### Secuencias
Esta capa se encarga de llevar el control de las conmutaciones dentro de una secuencia. Ofrece la posibilidad de configurar una secuencia y luego se encarga de gestionar el recorrido de la misma a los tiempos configurados.
Esta misma capa enciende los led correspondientes, en funcion de la secuencia configurada.

### Led
Gestiona el encendido o apagado de los Leds que se le solicita conmutar.

## Descarga
Abrir una terminal en la carpeta donde carga los proyectos dentro de firmware v3 y escribir
```
git clone https://github.com/mrds90/PmC_Actividad3.git
```
## Compilacion

* Abrir la terminal del CIAA launcher e ir a la ruta del firmware v3.
* Seleccionar el programa con el comando
```
make select_program
```
* Elegir la carpeta del repositorio descargado (PmC_Actividad2)
* Compilar el programa el programa en la misma terminal con:
```
make all
```
##  Descargar programa en edu_cia_nxp

* En la misma terminal y con la edu_ciaa_nxp conectada escribir

```
make download
```

## Help

Puede no tener seleccionado la placa correcta. Para corregir esto escriba
```
make select_board
```
y seleccione la edu_ciaa_nxp

Siempre debe estar en la ruta raiz de la carpeta clonada "firmware_v3" con la terminal de CIAA Launcher si desea usar los comandos.

## Autor

Marcos Dominguez
[@mrds90](https://github.com/mrds90)

Mario Aguilar
[@mario739](https://github.com/mario739)
