void setMogo( int pwr )
{

	motor[mogo] = pwr;

}

void setClaw( int pwr )
{

	motor[claw] = pwr;

}

void setLift( int pwr )
{

	motor[lLift] = motor[rLift] = pwr;

}
void liftTo(int encoderValue)
{
	if (encoderValue > fabs (SensorValue (lift)))
	{
		motor[lLift] = motor[rLift] = 127;
	}

}
void driverIntake()
{

	static int openPressed = 0;
	static int closePressed = 0;
	static int openToggled = 0;
	static int closeToggled = 0;

	if (vexRT[Btn7L]==1){
		if (!openPressed)
		{
			//change state
			openToggled=1 - openToggled;
			openPressed=1;
		}
		else
		 closeToggled = 0;
	}
	else{
		openPressed=0;
	}

	if (vexRT[Btn7R]==1){
		if (!closePressed)
		{
			//change state
			closeToggled=1 - closeToggled;
			closePressed=1;
		}
		else
			openToggled = 0;
	}
	else{
		closePressed=0;
	}

	if( openPressed )
		setClaw( 50 );
	else if( openToggled )
		setClaw( 20 );
	else if( closePressed )
		setClaw( -80 );
	else if( closeToggled )
		setClaw( -10 );

}

bool liftPidEnabled = false;
	int liftTarget=0;
task pid{
while (true){
	if (liftPidEnabled)
	setLift(myPID(liftTarget,LiftPidValues,lift));
	wait1Msec(20);
}
}

void driverLift()
{

	static int pidOn = 0;

	if(vexRT[Btn7D]==1){
		pidOn = 1;
		if( vexRT[Btn5D] || vexRT[Btn5U] )
			pidOn = 0;
	}

	if( vexRT[Btn5D] || vexRT[Btn5U] )
		pidOn = 0;

	if ( pidOn )
	{
		liftPidEnabled=true;
		liftTarget=-585;
	}
	else
	{
		liftPidEnabled=false;
		setLift( vexRT[Btn5D]*127 - vexRT[Btn5U]*127 );
	}

}
