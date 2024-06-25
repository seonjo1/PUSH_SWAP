# PUSH_SWAP
1. input 으로 들어온 수들의 정렬 방법을 찾아주는 push_swap 프로그램

2. 정렬 방법이 올바른지 확인해주는 checker 프로그램

## push_swap 프로그램 특징
### Stack 를 2개 이용한 정렬
- stack 2개 a, b 만을 이용해 수를 정렬
- 처음 input 으로 들어온 수들을 순서대로 stack a에 넣은 상태로 시작
- stack 개념으로 쓰지만 뒤에서 수를 꺼낼 수 있음
### 정해진 명령어만을 사용하는 정렬
- 정해진 명령어들 모음
  - sa (swap a): stack a 의 맨 위 2개의 숫자 위치 변경
  - sb (swap b): stack b 의 맨 위 2개의 숫자 위치 변경
  - ss: sa + sb 동시에 실행
  - pa (push a): stack b 의 맨 위 수를 stack a 의 맨 위로 push
  - pb (push b): stack a 의 맨 위 수를 stack b 의 맨 위로 push
  - ra (rotate a): stack a 의 맨 위 수를 맨 아래로 위치 변경
  - rb (rotate b): stack b 의 맨 위 수를 맨 아래로 위치 변경
  - rr: ra + rb
  - rra (reverse rotate a): stack a 의 맨 아래 수를 맨 위로 위치 변경
  - rrb (reverse rotate b): stack b 의 맨 아래 수를 맨 위로 위치 변경
  - rrr: rra + rrb
- input 으로 들어온 수들을 위 명령어들을 통해 정렬하는 방법 출력

## checker 프로그램 특징
### push_swap 프로그램을 통해 얻은 정렬 방법이 올바른지 판단
- 정렬 방법이 올바르면 "OK" 출력
- 정렬 방법이 틀리면 "KO" 출력
- checker의 input이 형식에 맞지 않으면 "Error" 출력

## push_swap 프로그램 작동 방식 간단한 설명
### merge sort 개념을 이용한 정렬
1. 처음 stack a에 있는 수 n 개를 Group 당 3 개씩, n / 3 개의 Group으로 만들어 stack b 에 옮기기 (3 개씩 묶인 Group은 내부적으로 정렬되어 있음)
2. stack b에 있는 Group n / 3 개를 Group 당 3 개씩, n / 9 개의 Group으로 만들어 stack a 에 옮기기 (9 개씩 묶인 Group은 내부적으로 정렬되어 있음)
3. 위 방법 처럼 Group의 개수를 1/3 으로 줄여가며 정렬해 1개의 Group이 남을 때까지 반복

## push_swap 프로그램 사용법
```
./push_swap "5 4 2 1 3"
```
- " " 안에는 원하는 수들을 공백으로 나눠 입력
- input 수들을 정렬하는 명령어들이 1줄에 1개씩 출력

## checker 프로그램 사용법
```
./checker "5 4 2 1 3"
sa
pb
pb
sa
pa
pa
rra
rra
rra
```
- " " 안에 정렬 시킬 수들을 공백으로 나눠 입력
- input 수들을 정렬하는 명령어들을 1줄에 1개씩 입력
- 명령어 입력이 끝났을때 eof를 주면 "OK" 또는 "KO" 출력
- input 이 올바르지 못한 경우 "Error" 출력

## build
```
make
```
- push_swap 프로그램 생성
```
make bonus
```
- checker 프로그램 생성
```
make clean
```
- push_swap, checker 를 만들때 생성된 .o 파일들 삭제
```
make fclean
```
- make clean + push_swap, checker 제거
```
make re
```
- make fclean + make

---
<img width="210" alt="스크린샷 2024-06-25 오후 5 33 40" src="https://github.com/seonjo1/PUSH_SWAP/assets/127729846/537f0802-0aba-4210-9469-3ab1571fdc69">
