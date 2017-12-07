# Project 3: Pong Game
## Introduction

Welcome to Pong! Here you will the project to make pong on your own MSP430!

## PONG
This is the base of the whole game. Everything is handled here!
  - Layers define the objects such as the redPaddle, whitePaddle, ball, & the playField
  - Regions get the information of these layers 
  - mlAdvance is the core of the collisions
  - p1() & p2() when given button move the paddle up and down
