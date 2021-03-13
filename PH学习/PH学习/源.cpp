header("Content-type: text/html; charset=utf-8");
ignore_user_abort(true);
set_time_limit(0);
date_default_timezone_set('PRC'); // �л����й���ʱ��

/* * * * * * ��Ҫ�޸ĵĵط�* * * * * *  */
$username = "weixin_43762735";//�����б�ҳ���û���ʶ
$page_count = 2;//���µ���ҳ��
$visit_count = 10; //ÿƪ���·��ʴ���
/* * * * * * ��Ҫ�޸ĵĵط�* * * * *  */

$csdn = "http://blog.csdn.net/";//csdn��ַ
echo "Start URLs...".PHP_EOL;
$list_id = get_list_id($username, $csdn, $page_count);
if (count($list_id) == 0){
	echo "NO articles!";
	exit();
}
print_r($list_id);
echo "grep URLs finshed. Total URL numbers: ".count($list_id).PHP_EOL;
echo "Start Visits...".PHP_EOL;;
get_visits($username, $csdn, $list_id, $visit_count);







/**
* ������ȡҳ���еĲ��͵�ַ��id
* @param unknown $username �����б�ҳ���û���ʶ
* @param unknown $csdn csdn��ַ
* @param unknown $page_count ���µ���ҳ��
*/
function get_list_id($username, $csdn, $page_count){
	//����������ȡҳ���еĲ��͵�ַ
	$pattern1 = '/\<h3 class="list_c_t"\>\<a href="\/'.$username.'\/article\/details\/(\d{7,8})"\>/';//����Ƥ������������ �б���ʽһ
	$pattern2 = '/\<span class="link_title"\>\<a href="\/'.$username.'\/article\/details\/(\d{7,8})"\>/';//�б���ʽ��
	$pattern3 = '/'.$username.'\/article\/details\/(\d{7,8})/';//�б���ʽ��

	//ѭ�������������б���ȡ����URL��ѭ������Ϊ����ʵ�ʵķ�ҳ��
	$list_id = [];
	for ($i = 1; $i <= $page_count; $i++) {
		$list_url = $csdn.$username."/article/list/$i";
		$html = curl_get_contents($list_url);
		if (preg_match_all($pattern1, $html, $arr)>0){
			if ($i == 1) {
				$list_id = $arr[1];
			}
			else {
				//��ÿ����ҳ����ȡ��URL�ϲ���һ���������У����㴦��
				$list_id = array_merge($list_id, $arr[1]);
			}
		}elseif(preg_match_all($pattern2, $html, $arr)>0){
			if ($i == 1) {
				$list_id = $arr[1];
			}
			else {
				//��ÿ����ҳ����ȡ��URL�ϲ���һ���������У����㴦��
				$list_id = array_merge($list_id, $arr[1]);
			}
		}elseif(preg_match_all($pattern3, $html, $arr)>0){
			if ($i == 1) {
				$list_id = $arr[1];
			}
			else {
				//��ÿ����ҳ����ȡ��URL�ϲ���һ���������У����㴦��
				$list_id = array_merge($list_id, $arr[1]);
			}
		}
		else
			break;
	}

	return array_unique($list_id);
}

/**
* ѭ�����ʴ���
* @param unknown $username �����б�ҳ���û���ʶ
* @param unknown $csdn csdn��ַ
* @param unknown $list_id ҳ���е����в��͵�ַ��id
* @param number $visit_count ÿƪ���·��ʴ���
*/
function get_visits($username, $csdn, $list_id, $visit_count = 10){
	//ѭ�����ʴ���
	$article_url = $csdn.$username.'/article/details/';
	for ($i = 1; $i <= $visit_count; $i++) {
		foreach($list_id as $value) {
			curl_get_contents($article_url.$value);
		}
		echo "loop times: $i".PHP_EOL;
	}

}

/**
* curlԶ�̻�ȡҳ��
* @param unknown $url URL��ַ
* @return mixed
*/
function curl_get_contents($url) {
	$headers = get_rand_ip();
	$curl = curl_init();
	curl_setopt($curl, CURLOPT_URL, $url);
	curl_setopt($curl, CURLOPT_BINARYTRANSFER, true);
	curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
	curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
	curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, 2);
	curl_setopt($curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:12.0) Gecko/20100101 Firefox/12.0");      //ģ�����������
	curl_setopt($curl, CURLOPT_TIMEOUT, 100);                               // ���ó�ʱ���Ʒ�ֹ��ѭ��
	curl_setopt($curl, CURLOPT_HEADER, 0);                                  // ��ʾ���ص�Header��������
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);                          // ��ȡ����Ϣ���ļ�������ʽ����
	$tmpInfo = curl_exec($curl);
	if (curl_errno($curl)) {
		print "Error: ".curl_error($curl);
	}
	else {
		curl_close($curl);
	}
	return $tmpInfo;
}

/**
* ����ṩ�˹��ڵ�IP��ַ
* @return multitype:string
*/
function get_rand_ip(){
	$ip_long = array(
		array('607649792', '608174079'), //36.56.0.0-36.63.255.255
		array('1038614528', '1039007743'), //61.232.0.0-61.237.255.255
		array('1783627776', '1784676351'), //106.80.0.0-106.95.255.255
		array('2035023872', '2035154943'), //121.76.0.0-121.77.255.255
		array('2078801920', '2079064063'), //123.232.0.0-123.235.255.255
		array('-1950089216', '-1948778497'), //139.196.0.0-139.215.255.255
		array('-1425539072', '-1425014785'), //171.8.0.0-171.15.255.255
		array('-1236271104', '-1235419137'), //182.80.0.0-182.92.255.255
		array('-770113536', '-768606209'), //210.25.0.0-210.47.255.255
		array('-569376768', '-564133889'), //222.16.0.0-222.95.255.255
		);
	$rand_key = mt_rand(0, 9);
	$ip = long2ip(mt_rand($ip_long[$rand_key][0], $ip_long[$rand_key][1]));
	$headers['CLIENT-IP'] = $ip;
	$headers['X-FORWARDED-FOR'] = $ip;

	$headerArr = array();
	foreach($headers as $n = > $v) {
		$headerArr[] = $n .':'.$v;
	}
	return $headerArr;
}
