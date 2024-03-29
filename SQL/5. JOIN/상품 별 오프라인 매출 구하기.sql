﻿SELECT P.PRODUCT_CODE, SUM(O.SALES_AMOUNT) * P.PRICE AS SALES 
FROM PRODUCT AS P
JOIN OFFLINE_SALE AS O
ON P.PRODUCT_ID = O.PRODUCT_ID
GROUP BY O.PRODUCT_ID -- 묶는 조건 따로 없으므로 HAVING 절은 X
ORDER BY SALES DESC, PRODUCT_CODE ASC;