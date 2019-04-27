# python27env

Simple project that will set the correct `PYTHONHOME` for different python versions before `python.exe` starts.

For python 2.7:

```
PYTHONHOME27_86=C:\Python27
PYTHONHOME27_64=C:\Python27-64
```

For python 3.7:

```
PYTHONHOME37_86=C:\Python37-32
PYTHONHOME37_86=C:\Python37-64
```

## Installation

Use CFF explorer to add an import to `!pythonenvXX.dll` in `pythonXX.dll` (for 2.7 installed globally, for 3 installed next to `python.exe`).