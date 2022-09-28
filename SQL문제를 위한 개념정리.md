My SQL -> ctrl + enter => 실행 

조회- SELECT)  
SELECT {column명} FROM {테이블명}  
SELECT {column명} FROM {스키마명.테이블명}  
SELECT * FROM {테이블명}			: 모든 col 의 데이터 조회  
  
  
필터링- WHERE)  
SELECT {column명} FROM {테이블명} WHERE {row명-조건}  
SELECT {column명} FROM {테이블명} WHERE num=5 AND name='hi';  
SELECT * FROM Customers WHERE cust_state<>'MI'   
	  - 같음 =, 같지않음 <>  
	  - 문자열type은 작은따옴표''  
	  - AND, OR 추가가능   
  
정렬- ORDER BY)  
SELECT {column명} FROM {테이블명} ORDER BY {정렬할col명} {내림/오름차순option}, {정렬할col명2} {option}, ...  
SELECT {column명} FROM {테이블명} ORDER BY 1	  
	  - ORDERBY 뒤의 정렬조건, 앞에서부터 차례대로 우선순위 가짐.   
	  - 내림/ 오름차순 option  
		  -ASC : 오름차순(def)  
		  -DESC : 내림차순  
  * 우선순위 -> SELECT, FROM, WHERE, ORDER BY  


