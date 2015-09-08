# BATTLESHIP
Homework assignment for Programming Foundations II. Problem found at:
 Link to assignment: http://csce.uark.edu/~lbg002/csce2014/homework/homework-1/
 
<h2>I. Problem Statement</h2>
<p>The goal of this assignment is to recreate the board game <a href="http://www.hasbro.com/common/instruct/battleship.pdf">Battleship</a> using object-oriented programming. To accomplish this, you should create a Ship class that stores information about a single ship in a player&#8217;s fleet and represent each player&#8217;s fleet as an array of these Ship objects. You are not limited to a single class, if you decide that it makes sense to use multiple classes in your program.</p>
<p>Your program should implement at least these components of the Battleship game:</p>
<ul>
<li>Players take turns placing their ships.</li>
<li>Until the game is over, players take turns attacking.
<ul>
<li>Player views the target and ocean grids.</li>
<li>Player selects a new target on the grid.</li>
<li>Opponent indicates whether the target was a hit or miss.</li>
<li>Opponent indicates if the hit ship was sunk.</li>
</ul>
<li>Game ends when one player has sunk all of the other player&#8217;s ships.</li>
</ul>
<p>The target and ocean grids should be the standard size of 10 x 10, usually labeled as 1-10 on the top and A-J on the side. Each player should begin with five ships:</p>
<ul>
<li>Carrier &mdash; 5 across</li>
<li>Battleship &mdash; 4 across</li>
<li>Cruiser &mdash; 3 across</li>
<li>Submarine &mdash; 3 across</li>
<li>Destroyer &mdash; 2 across</li>
</ul>
<p>You can see the complete rules to Battleship <a href="http://www.hasbro.com/common/instruct/battleship.pdf">at this link.</a> You may implement additional rules, like indicating the type of ship that was hit or displaying how many of the opponent&#8217;s ships have been sunk, but you are only required to implement the rules above.</p>
<h2>II. Design</h2>
<p>You should begin by thinking about what kind of data each Ship object will need and what kind of operations you can perform on them. Here are a few to help you get started (you are not required to use this information if you come up with a different approach):</p>
<ul>
<li>The size of the ship.</li>
<li>The placement of the ship on the grid.</li>
<li>A method to track how damaged the ship is (and whether it is destroyed).</li>
<li>A method to see if the ship is at a certain grid location.</li>
</ul>
<p>You should also think about the control flow of the program and how the main function will work. The control flow should follow the structure of the Battleship game as described above.</p>
