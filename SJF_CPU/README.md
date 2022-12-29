## 이 프로젝트는 CPU scheduling 실제로 구현해보고 평가해보기 위해 준비되었습니다.

* `src/my_sched.c` 내, `sched_update_cproc()`과 `sched_pick_cproc()` 함수 수정하여 자신만의 스케쥴링을 짜봅시다!
  * `sched_pick_cproc` 는 어떤 프로세스를 선택하여 스케쥴링을 할지 정하는 함수입니다. 현재는 간단한 FIFO list (`my_sched->clist`, `src/utility/list.c` 참조) 를 이용합니다.
  * `sched_update_cproc()` 는 선택된 프로세스에 시간을 얼만큼 할당할지 정하는 함수입니다. `cproc->sched_time`을 원하는 시간만큼으로 변경하세요.

### 평가기준
  * deadline을 얼마나 잘 지키는지 
  * turnaround time이 얼마나 짧은지
  * reponse time이 얼마나 짧은지
  * 각 스케쥴링 기법마다 위의 세가지 지표에 대한 우선순위가 있습니다. 최소 2가지 이상의 스케쥴링을 구현하고 결과에 대한 분석을 진행해주세요.

### 제출물
  * 1주차: 기존 코드 분석하여 보고서 2장 내 제출해주세요.
  * 2주차: 스케쥴링 방법 설명 및 결과분석 발표 5~10분 준비해주세요.

### Compile
  * `make` 명령으로 컴파일 가능합니다.
  * 헤더파일에 대한 수정이 있을 경우 `make clean; make` 해야 합니다.

### Running
```
  ./bin/my_cpu -c {# of clients (processes)}
```

### Results
  * 평균 turnaround time, 평균 response time, deadline을 지킨 프로세스들의 비율
