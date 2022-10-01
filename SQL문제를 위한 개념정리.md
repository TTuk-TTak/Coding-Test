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


------------------------------------------------------------------------------------------------------
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
  * 우선순위 -> SELECT, FROM, WHERE, GROUP BY, ORDER BY

제한- LIMIT, OFFSET)
 - LIMIT으로 개수제한 주로 상위N개결과 뽑는데 쓰임 
 - OFFSET은 LIMIT과 함께 사용되어 주로 '페이지처리'에 사용 
SELECT {column명} FROM {테이블명} LIMIT {n 선택개수} OFFSET {건너뛸 데이터 개수} 
SELECT * FROM Products ORDER BY prod_price DESC LIMIT 2 OFFSET 3;
 : 가격비싼 제품 중 상위4,5번째 제품 

필터- IN)
 - 다중 or 연산자의 축약 ver
 - WHERE col=a OR col=b OR col=c ... = WHERE col IN (a,b,c...)
SELECT {column명} FROM {테이블명} WHERE {row명} IN {(포함시킬 조건1, 조건2, ..)}
SELECT * FROM Customers WHERE cust_state IN ('MI', 'OH')

필터 - BETWEEN)
----------------------------------------------------------------------------------------------------------------
수세기- COUNT)
SELECT count(*) FROM apt
: apt테이블의 전체 데이터 개수 반환 

그룹화,중복제거- GROUPBY )
SELECT {그룹으로 묶은조건, COUNT(*)} FROM {테이블명} GROUP BY {그룹으로 묶을 조건}
SELECT dong,count(*) FROM apt_list GROUP BY dong	: 동별로 아파트개수가 나옴
SELECT dong FROM apt_list GROUP BY dong		: 존재하는 동만 중복제거되어 나옴 

별칭 지정)
SELECT {column명} {별칭명} FROM {테이블명}
 * 단, WHERE절에서는 정의한 별칭 사용 불가 *** 
 * 테이블에 {별칭명}으로 표시됨 *** 
 * {테이블명}에 별칭 붙이는 건 안됨 

null값 처리)
SELECT {col명}, IFNULL({처리할col명},{'대체할 txt'})		


DATETIME 타입)
 YEAR(), DAY(), MONTH() .. 등 함수로 사용 가능 
 

서브쿼리)
SELECT *
FROM(
    SELECT NAME, COUNT(*) COUNT		// COUNT의 별칭 설정 후
    FROM ANIMAL_INS
    WHERE NAME IS NOT NULL		// null이 아닐 경우 
    GROUP BY NAME
    ORDER BY NAME
) A					// 왜인진 모르지만 A가 붙어야됨 
WHERE COUNT>=2				// 바깥 쿼리에서 별칭으로 조건 정의 

JOIN )
inner JOIN) 
- 양쪽 테이블에 모두 정보가 있어야 함(key일치)
SELECT * FROM apt_list A, apt_num B		// 여러테이블을 불러와 별칭을 지정해 사용
WHERE a.col1 = b.col2			// 쪼인 key 매핑 
outer JOIN)
- 양쪽 중 한쪽에만 정보가 있어도 되는 조인 
- 데이터가 존재하지 않더라고 NULL값으로 표시하며 모두 표시해줌 
SELECT b.price FROM area a
LEFT OUTER JOIN apt_list b
 	ON a.col1 = b.col2
	AND b.col2=2020

   
