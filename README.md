# 4253B Tipping Point Early Season Code

Here is the software we used in the early season of [Tipping Point](https://www.youtube.com/watch?v=H8XcvADUXTE). 

We used [Pathplanner](https://github.com/mjansen4857/pathplanner) for path generation and [Okapilib](https://github.com/OkapiLib/OkapiLib) and [PROS](https://pros.cs.purdue.edu/) for our code. 

## Installation

Download at your own risk. 

## Features & Usage

* Chassis

We used custom PID and linear motion profiles for lateral movement. For more complex movements (such as curves), we used [Pathplanner](https://github.com/mjansen4857/pathplanner) to transform bezier curve paths into motion profiles. 

* Lift

We used [Okapilib's](https://github.com/OkapiLib/OkapiLib) AsyncPosPIDController to accurately control lift movements. Since the controller is asynchronous, we could easily integrate it into our code. Check out its documentation [here](https://okapilib.github.io/OkapiLib/classokapi_1_1AsyncPosPIDController.html). 

Checkout a more detailed explanation [here](https://github.com/Ryan4253/4253B-Tipping-Point-Worlds#features). 

## License
[MIT](https://choosealicense.com/licenses/mit/)
