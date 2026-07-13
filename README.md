# miniRT
### 간단한 3D 레이트레이서
![예시](./miniRT_test.png)

## 프로젝트 소개

miniRT는 C를 사용하여 norminette라는 코딩 컨벤션을 지키며 작성해야하는 ecole42 4circle 과제입니다.

빛 반사, 굴절, 카메라 왜곡 처리 없이, 카메라에서부터 시작해 물체에 가장 먼저 닿은 지점을 찾고. 그 지점으로부터 다른 물체에 의해 가려지지 않고 점광원에 도달할 수 있는지 검증하는 간단한 방식의 레이트레이서입니다.

[Phong lightning](https://en.wikipedia.org/wiki/Phong_reflection_model)을 기반으로 했습니다

## project info
```md
Program name : miniRT
Makefile : all, clean, fclean, re
허용 함수 :
  - open, close, read, write, printf, malloc, free, perror, strerror, exit
  - All funcions of the math library
  - All funtions of thr minilibx(mlx : gui 앱 라이브버리)

start : 2023.08.07 - 팀원 구하느라 좀 늦어지는김에 일주일 휴식함
end   : 2023.09.08
기간  : 33일
```

## 제작 기록
팀원분과 나 모두 기벡을 배운 상태라 벡터 연산에 대해서는 생략하고 바로 phong lightning 먼저 학습할 수 있었음.

구현 자체는 역할을 나누어 진행했지만 학습 자체는 모든 과정에 대해 같이 공부했었음

이미 법선벡터, 판별식, 입사각과 반사각, 내적, 외적을 아는 입장에서는 수학적인 개념은 딱히 새로운게 없었지만 그걸 c로 구현해야해서 어떻게 수학적 공식을 코드로 구현하는가를 고민해가며 배울 수 있었음

문제는 공식에서 쓰인 세부적인 개념을 아는것과 그 공식대로라면 어떤 경우에 어떤 값이 나와 어떻게 분류하고 동작시킬지 나누는게 진짜 일이라는걸 느낌

특히 [원기둥](https://www.illusioncatalyst.com/notes_files/mathematics/line_cylinder_intersection.php)이 기둥부분과 원 부분을 한번에 계산 가능한 도형이 아니라 많이 복잡해졌음

심지어 평가를 다 성공적으로 받아 과제 통과 이후 카메라가 원기둥의 중심선에 있고 카메라의 벡터가 원기둥의 것과 같을 때 (원기둥 원의 법선벡터와 같을 때) hit 처리 못해서 1px 비어버리는 부분을 뒤늦게 발견했음
(해당 레포는 평가받은 기준의 레포라서 수정되지 않은 상태)



## 작동 방법
Makefile 사용법
```shell
make all # 실행파일 생성
make clean # 실행파일 제외 모든 생성된 파일 제거
make fclean # 실행파일 포함해 모든 생성된 파일 제거
make re # 모든 생성파일 제거 후 실행파일 재생성

make test # test dir의 만들어둔 잘못된 문법의 rt파일들을 실행해 모든 종류의 예외처리를 확인할 수 있고 마지막에 (나름 열심히 구성한) 다양한 도형을 넣은 파일 렌더링
make norm # 42 C 
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

Cylinder
identifier  
cy	 0,4,3  0,1,0	 2 2  200,20,20

Sphere
identifier  
sp  0,10,0 2.5 150,80,80
```
