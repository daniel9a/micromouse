//
//  AssertionHandler.h
//  micromouse-xcode
//
//  Created by Erick Sanchez on 4/20/16.
//  Copyright © 2016 Erick Sanchez. All rights reserved.
//

#ifndef AssertionHandler_h
#define AssertionHandler_h

#include "Memory.h"

#ifdef __MK20DX256__ // Teensy Compile

inline static void logError( int code ) {
    if (Micromouse::Memory::read(Micromouse::ERROR_MEMORY)) //Validate if ERROR_MEMORY has been initilized
        Micromouse::Memory::write(Micromouse::ERROR_MEMORY, 0);
    //Read and increment to the next error state, as well as validate to loop back to 1 if incremented to 21
    int intNextIndex = Micromouse::Memory::read(Micromouse::ERROR_MEMORY) +1;
    intNextIndex = intNextIndex > 20 ? 1 : intNextIndex;
    
    //Find next state address and save code as well as the most recent error state in ERROR_MEMORY
    int intNextStateAddress = Micromouse::ERROR_MEMORY +intNextIndex * 4;
    Micromouse::Memory::write( intNextStateAddress, 15);
    Micromouse::Memory::write( Micromouse::ERROR_MEMORY, intNextIndex);
    
}

//Prints to concole using Logger(..) << code and metadata of the assertion
#define assertion(condition,code) \
( \
(__builtin_expect(!(condition), 0) ? (void)(logError(code)) : (void)0) \
)

#else

//Prints to concole using the definition of assert(e) declared in assert.h
#define assertion(condition,code) \
( \
(__builtin_expect(!(condition), 0) ? __assert_rtn(__func__, __FILE__, __LINE__, #condition) : (void)0) \
)

#endif

#endif /* AssertionHandler_h */
