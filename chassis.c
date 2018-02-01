
void setChassis( int lPwr, int rPwr )
{

	motor[bLDrive1] = motor[bLDrive2] = motor[fLDrive] = lPwr;

	motor[bRDrive1] = motor[bRDrive2] = motor[fRDrive] = rPwr;

}
void setChassis( int Pwr)
{

	motor[bLDrive1] = motor[bLDrive2] = motor[fLDrive] = Pwr;

	motor[bRDrive1] = motor[bRDrive2] = motor[fRDrive] = Pwr;

}
bool turnPidEnabled=false;
bool drivePidEnabled = false;
	int driveTarget=0;
	int turnTarget=0;
task drivePid{
while (true){
	int power=0;
	int turn=0;
	if (drivePidEnabled)
	power=(myPID(driveTarget,drivePidValues,drive));
if (turnPidEnabled)
	turn=(myPID(turnTarget,turnPidValues,SensorValue[drive]-SensorValue[drive1]));
setChassis(power+turn,power-turn);

	wait1Msec(20);

}


}
