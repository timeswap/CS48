TwoTD: User Instructions

Index
====

1.Introduction
2.Installation
3.Usage
	3.1 Functions
	3.2 How to play
4.Concluding remarks


1. Introduction
===========

There are plenty of Tower Defense games out there from the perspective of the valiant defenders, but what about the evil masterminds who send the evil monsters to their deaths? This Tower Defense will allow two players to play, one as the classic defensive tower builder, and the other as the "bad guy," in control of what monsters are being sent and when their abilities are activated.


2.Installation
===========

The game files are stored in a .zip file. The user needs to first download Qt and then start the game using Qt Creator. To open the game folder, you need to open the .pro file using Qtcreator.

3.Usage
=======

3.1 Functions 
~~~~~~~~~~~

3.1.1 Scene Class
3.1.1.1 CreateMonster – creates a new monster
	Parameters: none
	Return type: void
3.1.1.2 CreateTower – creates a new tower
	Parameters: none
	Return type: void
3.1.1.3 setTowerBuildModeOn – sets m_inTowerBuildMode to true
	Parameters: none
	Return type: void
  3.1.1.4 setTower1ToBeBuild – sets the type of tower to be built
	Parameters: none
	Return type: void
 
3.1.2 MobileUnit Class
3.1.2.1 lifePoints - returns the health of the monster
	Parameters: none
	Return type: int
3.1.2.2 isFinished – whether or not the game is done with the monster
	Parameters: none
	Return type: bool
3.1.2.3 paint – paints the monster
Parameters: QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget
	Return type: void
3.1.2.4 advance – moves or explodes the monster, depending on the phase
	Parameters: phase
	Return type: void
3.1.2.5 touched – damages the monster
	Parameters: hurtpoints – the amount by which the monster is damaged
	Return type: void

3.1.3 SlimeMonster Class - a child class of the Monster class
	Specifications: activateAbility() - slime monsters have the ability to regenerate health

3.1.4 SimpleTower Class
3.1.4.1 paint – draws the tower
Parameters: QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget
	Return type: void
3.1.4.2 advance – if the phase is 0, searches for targets, otherwise, advances to the given phase
	Parameters: phase 
	Return type: void
3.1.4.3 searchTarget – looks for targets in range
	Parameters: none
	Return type: void
3.1.4.4 shoot – touches the target
	Parameters: none
	Return type: void


3.2 How to play 
~~~~~~~~~~~~~~~

1.Download QT if not installed on computer
2.Run QtCreator for TwoTD
3.Open the TwoTD.pro file
4.Press control b to build the files
5.Press control r to run the program
6.One player presses “enter” to exit the instruction screen and start the game
7.The tower player places towers using the mouse
a.The player selects a tower type
b.The UI displays a description of the tower
c.Player can place the tower by clicking on a location on the map or, to cancel the selection, click on another tower type button
d.If the cost exceeds the player’s resources, the player cannot build the tower
8.The monster player uses the keys 1,2,3 to select monster types
a.The UI gives a description and the option to create the monster for the given price
b.The player may decide to purchase the monster by hitting the space bar, in which case it will appear on the map and move automatically to the end of the path
c.If the user’s resources are lower than the cost, the player cannot create the monster
9.Game play continues until the tower player’s lives are depleted (by letting monsters successfully cross the map), or the timer runs out
10.The UI shows who won.
