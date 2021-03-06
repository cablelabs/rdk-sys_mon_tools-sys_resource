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
#include	<assert.h> 

#include	"IMemoryPartition.h"
#include	"procStatmS.h"

template<> ProcStatmS* create<ProcStatmS>(IMemoryPartition *partition)
{
#if USE_CUSTOM_MM
	assert(partition);
	if (partition) return new (partition) ProcStatmS();
	return 0;
#else
	return new ProcStatmS();
#endif
}

template<> void destroy<ProcStatmS>(ProcStatmS* p, IMemoryPartition *partition)
{
#if USE_CUSTOM_MM
	if (p) 
	{
		p->~ProcStatmS();
		assert(partition);
		if (partition) partition->deallocate(p);
	}
#else
	delete p;
#endif
}
