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
#pragma once

#include <Windows.h>
	using namespace System;

ref class ChronoClass
{
private:
	int hours;
	int minutes;
	int seconds;
	int milliseconds;
	int systemTime;

	static const int maxHours = 100;
	static const int maxMinutes = 60;
	static const int maxSeconds = 60;
	static const int maxMilliseconds = 1000;
public:
	ChronoClass(void);
	~ChronoClass();

	int getHours();
	int getMinutes();
	int getSeconds();
	int getMilliseconds();

	void increase();
	void restart();
	void increaseSleep();
	void increaseSystem();

	String^ toStringChrono();
};

