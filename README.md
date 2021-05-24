## Semester work

### The first part of the work in fourth semester included:
* work with audio (slicing and saving)
* fourier transform (we had to implement two types of fourier transform - discrete and fast fourier transform). They are both in program `fourier.cpp`.

### Vad.cpp
The vad.cpp program works with audio, the format of which is wav. This program breaks audio into pieces in which continuous speech or sound is heard. After that, it saves these pieces as separate audio files.

#### To check the work of program vad.cpp, you need
* download all using command `git clone https://github.com/i-n-d-i/audio` 
* compile program using command `g++ vad.cpp -o vad`
* run program, using command `./vad audio.wav 0.1 0.01`

### Fourier.cpp
The Fourier transform (FT) decomposes a function (often a function of time, or a signal) into its constituent frequencies. A special case is the expression of a musical chord iт terms of the volumes and frequencies of its constituent notes.

In simple words, using the fourier transform, we get a complex spectrum from real numbers. And after performing the inverse fourier transform, we get the same vector of real numbers. Fast fourier transform does the same, but in a shorter amount of time.

#### To check the work of program fourier.cpp, you need: 
* compile program using command `g++ fourier.cpp -o fourier`
* run program using command `./fourier`

#### Example of program's work:
```
Start function:
Re: 1.000 Im: 0.000
Re: 6.000 Im: 0.000
Re: 2.000 Im: 0.000
Re: 5.000 Im: 0.000
Re: 3.000 Im: 0.000
Re: 4.000 Im: 0.000
Re: 5.000 Im: 0.000
Re: 8.000 Im: 0.000

*****Fourier Transform*****
Spectr:
Re: 4.250 Im: 0.000
Re: 0.192 Im: 0.463
Re: -0.375 Im: 0.375
Re: -0.692 Im: -0.287
Re: -1.500 Im: -0.000
Re: -0.692 Im: 0.287
Re: -0.375 Im: -0.375
Re: 0.192 Im: -0.463

Final function:
Re: 1.000 Im: 0.000
Re: 6.000 Im: 0.000
Re: 2.000 Im: -0.000
Re: 5.000 Im: -0.000
Re: 3.000 Im: -0.000
Re: 4.000 Im: 0.000
Re: 5.000 Im: 0.000
Re: 8.000 Im: -0.000

*****Fast Fourier Transform*****
Spectr:
Re: 4.250 Im: 0.000
Re: 0.192 Im: 0.463
Re: -0.375 Im: 0.375
Re: -0.692 Im: -0.287
Re: -1.500 Im: -0.000
Re: -0.692 Im: 0.287
Re: -0.375 Im: -0.375
Re: 0.192 Im: -0.463

Final Function:
Re: 1.000 Im: 0.000
Re: 6.000 Im: -0.000
Re: 2.000 Im: 0.000
Re: 5.000 Im: -0.000
Re: 3.000 Im: 0.000
Re: 4.000 Im: 0.000
Re: 5.000 Im: -0.000
Re: 8.000 Im: -0.000
```
