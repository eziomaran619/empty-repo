'use strict'

var canvas = document.getElementById("gameCanvas") ;
var context = canvas.getContext("2d") ;

var coordinateEquivalentForAction = {
	"moveUp":{x:0,y:-1},
	"moveRight":{x:1,y:0},
	"moveDown":{x:0,y:1},
	"moveLeft":{x:-1,y:0}
} ;

var animationFrameIndexEquivalentForAction = {
	"moveUp":0,
	"moveRight":1,
	"moveDown":2,
	"moveLeft":3
} ;