# TDA7439

***STM32*** LL(Low-Layer) C library. TDA7439 is a three-band digitally-controlled audio processor.\
See datasheet: [link](https://www.st.com/resource/en/datasheet/cd00004906.pdf)

### Features

- Full feature support(volume, bass, treble etc)
- Easy to use
- No HAL dependencies

<img src="https://github.com/ximtech/TDA7439/blob/main/example/view.PNG" alt="image" width="300"/>

### Add as CPM project dependency

How to add CPM to the project, check the [link](https://github.com/cpm-cmake/CPM.cmake)

```cmake
CPMAddPackage(
        NAME TDA7439
        GITHUB_REPOSITORY ximtech/TDA7439
        GIT_TAG origin/main)
```

### Project configuration

1. Start project with STM32CubeMX:
    * [I2C configuration](https://github.com/ximtech/TDA7439/blob/main/example/config.PNG)
2. Select: Project Manager -> Advanced Settings -> I2C -> LL
3. Generate Code
4. Add sources to project:
```cmake
add_subdirectory(${STM32_CORE_SOURCE_DIR}/I2C/Polling)  # add I2C to project

include_directories(${TDA7439_DIRECTORY})   # source directories
file(GLOB_RECURSE SOURCES ${TDA7439_SOURCES})    # source files
```

3. Then Build -> Clean -> Rebuild Project

### Wiring

- <img src="https://github.com/ximtech/TDA7439/blob/main/example/wiring.PNG" alt="image" width="300"/>

### Usage

***NOTE: For correct IC work need use level converter***
```c
#include "TDA7439.h"

int main() {

   I2CStatus processorStatus = initTDA7439(I2C1);
   if (processorStatus != I2C_OK) {
        Error_Handler();
   }

   setStereoInputTDA7439(TDA7439_INPUT_1); // switch to sound source input
   setInputGainTDA7439(TDA7439_GAIN_14dB);
   setVolumeTDA7439(TDA7439_VOLUME_MINUS_6dB);

   setRightSpeakerAttenuationTDA7439(TDA7439_ATTENUATION_0dB); // set default attenuation, otherwise speakers will be muted
   setLeftSpeakerAttenuationTDA7439(TDA7439_ATTENUATION_0dB);
   
}
```
