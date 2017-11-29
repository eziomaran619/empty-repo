'use strict'

var game = new Game() ;

function gameLoop() {
	game.update() ;
	game.draw() ;

	requestAnimationFrame(gameLoop) ;
}

var startGame = requestAnimationFrame(gameLoop) ;