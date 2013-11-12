/*
        Copyright 2013 Luis Valero Martin

        This file is part of Chrono.

        Chrono is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        SubEditor is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with SubEditor.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "ChronoClass.h"


ChronoClass::ChronoClass(void)
{
	hours = 0;
	minutes = 0;
	seconds = 0;
	milliseconds = 0;
	systemTime = 0;
}

ChronoClass::~ChronoClass(){}

int ChronoClass::getHours(){
	return hours;
}
int ChronoClass::getMinutes(){
	return minutes;
}
int ChronoClass::getSeconds(){
	return seconds;
}
int ChronoClass::getMilliseconds(){
	return milliseconds;
}

void ChronoClass::increase(){
	milliseconds++;
	if(milliseconds == maxMilliseconds){
		milliseconds = 0;
		seconds++;
		if(seconds == maxSeconds){
			seconds = 0;
			minutes++;
			if(minutes == maxMinutes){
				minutes = 0;
				hours++;
				if(hours == maxHours){
					hours = 0;
				}
			}
		}
	}
}
void ChronoClass::restart(){
	hours = 0;
	minutes = 0;
	seconds = 0;
	milliseconds = 0;
	systemTime = 0;
}
void ChronoClass::increaseSleep(){
	increase();
	Sleep(1);
}
void ChronoClass::increaseSystem(){
	if(systemTime != GetTickCount()){
		systemTime = GetTickCount();
		increase();
	}
}

String^ ChronoClass::toStringChrono(){
	String^ text;
	String^ sh;
	String^ sm;
	String^ ss;
	String^ sms;

	if(hours < 10) 
		sh = "0"+hours.ToString();
	else 
		sh = hours.ToString();
	if(minutes < 10) 
		sm = "0"+minutes.ToString();
	else 
		sm = minutes.ToString();
	if(seconds < 10) 
		ss = "0"+seconds.ToString();
	else 
		ss = seconds.ToString();
	if(milliseconds < 10) 
		sms = "00"+milliseconds.ToString();
	else if(milliseconds < 100) 
		sms = "0"+ milliseconds.ToString();
	else 
		sms = milliseconds.ToString();

	text = sh+":"+sm+":"+ss+":"+sms;

	return text;
}