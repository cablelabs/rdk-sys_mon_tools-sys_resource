/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#include <sys/time.h>

struct timespec clock_getdiff(struct timespec *start, struct timespec *end)
{
	struct timespec temp;
	temp.tv_nsec = end->tv_nsec - start->tv_nsec;
	if (temp.tv_nsec < 0) 
	{
		temp.tv_sec = end->tv_sec - start->tv_sec - 1;
		temp.tv_nsec += 1000000000L;
	} 
	else 
		temp.tv_sec = end->tv_sec - start->tv_sec;

	return temp;
}


