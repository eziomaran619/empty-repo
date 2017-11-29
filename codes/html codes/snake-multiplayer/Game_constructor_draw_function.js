'use strict'

Game.prototype.draw = function() {
	context.clearRect(0,0,canvas.width,canvas.height) ;
	context.drawImage(spriteSheets.head,64*player1.animationFrameIndex,0,64,64,
		player1.position.x,player1.position.y,32,32) ;
} ;