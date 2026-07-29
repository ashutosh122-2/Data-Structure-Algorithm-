WITH split_to_array AS (
	SELECT 
		p.product_id, 
		p.product_name, 
		p.description, 
		j.split_char
	FROM products p
	CROSS JOIN JSON_TABLE(
		CONCAT('["', REPLACE(p.description, ' ', '", "'), '"]'),
		'$[*]' COLUMNS (split_char VARCHAR(255) PATH '$')
	) j
)
SELECT product_id, product_name, description
FROM split_to_array
WHERE length(split_char) = 11
AND BINARY substring(split_char,1,2) = 'SN'
AND substring(split_char,7,1) = '-'
AND substring(split_char,3,1) BETWEEN '0' AND '9'
AND substring(split_char,4,1) BETWEEN '0' AND '9'
AND substring(split_char,5,1) BETWEEN '0' AND '9'
AND substring(split_char,6,1) BETWEEN '0' AND '9'
AND substring(split_char,8,1) BETWEEN '0' AND '9'
AND substring(split_char,9,1) BETWEEN '0' AND '9'
AND substring(split_char,10,1) BETWEEN '0' AND '9'
AND substring(split_char,11,1) BETWEEN '0' AND '9'
ORDER BY product_id;