# MicroMouse #

## Branches
* master : code that has been successfully tested on mouse and in sim
* sim : code that has been successfully tested in dev
* dev : code that successfully compiles and has been self tested

![alt branches](https://github.com/SRJC-Computer-Science-Club/micromouse/blob/master/workflow.png)

*the general workflow*

#### Git tutorials

(*if you're new to git watch this first:* https://www.youtube.com/watch?v=0fKg7e37bQE)

basic example of this workflow: https://www.youtube.com/watch?v=oFYyTZwMyAg


## Program flow

![alt branches](https://github.com/SRJC-Computer-Science-Club/micromouse/blob/dev/Charts/flow%20v02.png)

## Project Divisions

### Pathfinding

* find shortest path

* talk with mapping

* talk with motion control

### mapping

* track position

* locate walls

* explore maze

* detect finish cell

* talk with motion control

* talk with pathfinding

* talk with hardware

### motion control

* moving

* turning

* speed control

* collision avoidance

* talk with mapping

* talk with pathfinding

* talk with hardware

### hardware


* microcontroller (likely teensy or micro arduino): https://www.pjrc.com/store/teensy32.html

* sensors
 * proximity/range finder : https://www.pololu.com/category/79/sharp-distance-sensors

* body

* wheels - https://www.pololu.com/  

* motors -  
 * dual-shaft : https://www.pololu.com/category/60/micro-metal-gearmotors
 * hall-effect quadrature encoders: https://www.pololu.com/product/3081
 * H-bridge: https://www.sparkfun.com/products/315
   * http://itp.nyu.edu/physcomp/labs/motors-and-transistors/dc-motor-control-using-an-h-bridge/
 * current sensor for stalls: https://www.pololu.com/product/1185

* batteries
