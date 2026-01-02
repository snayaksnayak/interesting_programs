<?php 
$result_prime_number = array();
$number = 2; 
$loop=0;
while(true){
	$division_count = 0; 
	for($i = 2;$i <= $number/$i; $i++){
		if(($number % $i) == 0){
			$division_count++;
		} 
		$loop++;
	}

	if($division_count < 1){
		array_push($result_prime_number,$number);
	}

	if(count($result_prime_number) == 100)
	{
		echo $loop;
		var_dump($result_prime_number); 
		exit();
	} 
	$number++;
}
?>