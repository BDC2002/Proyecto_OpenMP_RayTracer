# Proyecto_OpenMP_RayTracer
Proyecto_OpenMP_RayTracer -  Programación Paralela - Grupo 5

## Resumen
El presente proyecto implementa un trazador de rayos (Ray Tracer) básico en C++, cuyo objetivo es generar una imagen 3D mediante el cálculo independiente del color de cada píxel de la pantalla. Se utiliza una cámara simple, un modelo geométrico compuesto por una esfera y un plano, y pruebas de intersección rayo-objeto para determinar el color final de cada píxel.

El proceso de renderizado es inherentemente paralelo debido a que el cálculo de cada rayo es independiente de los demás, lo que constituye un caso de paralelismo masivo o embarrassingly parallel, tal como se especifica en el enunciado del proyecto. Por ello, se empleará OpenMP para paralelizar el bucle principal de píxeles mediante la directiva #pragma omp parallel for, lo que permite distribuir el trabajo entre múltiples hilos de ejecución aprovechando arquitecturas multinúcleo.

En este avance se implementa la versión secuencial completa, incluyendo las intersecciones rayo–esfera y rayo–plano, y la generación del archivo de salida en formato PPM. 
#*En las siguientes entregas se integrará el modelo de iluminación y se evaluará el speedup obtenido al variar el número de hilos, comparando los tiempos entre la versión secuencial y la versión paralela.*#
## Abstract
This project implements a basic ray tracer in C++, whose objective is to generate a 3D image by independently calculating the color of each pixel on the screen. A simple camera, a geometric model composed of a sphere and a plane, and ray-object intersection tests are used to determine the final color of each pixel.

The rendering process is inherently parallel because the calculation of each ray is independent of the others, which constitutes a case of massively parallel or embarrassingly parallel processing, as specified in the project statement. Therefore, OpenMP will be used to parallelize the main pixel loop using the #pragma omp parallel for directive, which allows the work to be distributed among multiple threads, taking advantage of multi-core architectures.

## Fundamento Teórico
3.1. Algoritmo de Ray Tracing

El trazado de rayos es un método de renderizado basado en simular matemáticamente el recorrido de un rayo que parte desde la cámara hacia la escena. Para cada píxel se genera un rayo primario:
Ray ray(camera, Vector3(px, py, -1).normalize());
El algoritmo sigue tres pasos fundamentales:

1. Cálculo de intersección

Cada rayo se prueba contra los objetos presentes en la escena.
En la implementación hay dos objetos principales:

- Esfera:
La intersección rayo-esfera se calcula a partir de la ecuación cuadrática:
Vector3 oc = ray.origin - center;
double b = 2 * oc.dot(ray.dir);
double c = oc.dot(oc) - radius * radius;
double disc = b*b - 4*c;

Si el discriminante disc es mayor o igual a cero, existen soluciones reales y el rayo intersecta la superficie.

- Plano:
El plano está definido por su normal y un desplazamiento:
t = -(normal.dot(ray.origin) + d) / denom;
con denom = normal.dot(ray.dir) verificando que no sea un rayo paralelo.

2. Cálculo de la normal

Aunque aún no se usa la iluminación, la normal es esencial para futuros modelos de sombreado.
En una esfera se calcula como:
normal = (punto - centro).normalize();

3. Cálculo de la iluminación / sombreado

En el avance se asigna un color base:
if (hitSphere) r = 255;
else if (hitPlane) g = 255;
else b = 255;

3.2. Paralelismo y OpenMP

El renderizado de una imagen es un caso típico de paralelismo de datos masivo, debido a que:

- Cada píxel es independiente.
- Cada rayo se procesa sin depender del resultado de otros.
- La carga de trabajo se divide naturalmente en miles de iteraciones.

Por estas razones, OpenMP es ideal para paralelizar el bucle de renderizado. Tal como establece los lineamientos del proyecto, la paralelización principal debe aplicarse al doble bucle:
for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
    }
}


## Diseño e Implementación

## Resultados y Análisis
