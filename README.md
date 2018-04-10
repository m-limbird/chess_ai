This repository is for a chess AI that will make decisions for what move to make in a chess game and send commands to a robotic arm that will implement the changes on an actual chessboard. 

There are a lot of things to do, so I will start a list now:

1) I need a way to port over some of the logic from the javascript version of chess to a cpp implementation so that I can control the robotic arm
2) I will need to write sections to send the code after figuring out which move to do
3) I will need a vision system for seeing what the state of the board is after the actual player moves a piece (will require some sort of kalman filter, and other belief states about pieces)
4) May need to add encoders to the robot to have better control over the position of the arms
5) Need some sort of actuators for the pneumatic system of the arm
6) Need some sort of web interface so that players can play from afar

Thats all I have now, but this will be updated as I go along.
