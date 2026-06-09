# miniRT

## project info
```md
Program name : miniRT
Makefile : all, clean, fclean, re
허용 함수 :
  - open, close, read, write, printf, malloc, free, perror, strerror, exit
  - All funcions of the math library
  - All funtions of thr minilibx(mlx : gui 앱 라이브버리)
```

### 작동 방법
Makefile 사용법
```Makefile
```

해석할 파일이 될 하나의 인자가 필요하다
```shell
./miniRT [filename].rt
```

해석할 파일의 요소 해석
```rt
Ambient lightning
identifier  ratio[0.0, 1.0]   RGB
A	           0.2					    255,255,255

Camera
identifier  location(x,y,z)  vector  FOV
C           20,-2,3          -1,0,0  180

Light (점광원)
identifier  location(x,y,z)  ratio[0.0,1.0]  RGB
L           0,4.5,3          0.7             255,255,255

Plane
identifier  location(x,y,z)  vector  RGB
pl          0,0,-24		0,0,1					10,10,255


identifier  
cy	 0,4,3  0,1,0	 2 2  200,20,20


identifier  
sp  0,10,0 2.5 150,80,80
```
