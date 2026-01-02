<?php
$count_2=0;
$n=600;
$loop=0;
for($i=2;$i<=$n;$i++){
	$count=0;
	for($j=1;$j<=$i;$j++){
		if( ( $i % $j ) == 0 ){
			$count++;
		}
		$loop++;
	} 
	if($count==2){
		$count_2++;
	}
	if($count_2==100){
		echo $loop;
		exit();
	}
}
?>
