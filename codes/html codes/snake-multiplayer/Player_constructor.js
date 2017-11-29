'use strict'

function Player(up,right,down,left) {
	this.position = {x:100,y:100} ;
	this.velocity = {x:0,y:0} ;
	this.speed = 4 ;
	this.controlKeyCodeForAction = {
		"moveUp":up.charCodeAt(0),
		"moveRight":right.charCodeAt(0),
		"moveDown":down.charCodeAt(0),
		"moveLeft":left.charCodeAt(0)
	} ;
	this.animationFrameIndex = 1 ;
}

var player1 = new Player("W","D","S","A") ; 
var player2 = new Player("I","L","K","J") ;