### Question №1

There is one partition / 10 Gb.
When trying to create a file of size 2Gb you get the message "No space left on device".

df shows this:
```
user@host$ df -h
Filesystem      Size  Used Avail Use% Mounted on
/dev/md1        10G   10G  0   100% /
```
du shows this:
```
user@host$ sudo du -sh /
5G    /
```

Why so?

#### Answer:

inodes is ended. With help of `df -ih` we can see that. If not, there is deleted file which used by another process. You can see that process with help of `lsof | grep '(deleted)'` and then restart the process.


### Question №2

You have nginx-access.log

Log format:
```
$remote_addr $host [$time_local] "$request" $status $upstream_cache_status "$upstream_addr" $body_bytes_sent "$http_referer" "$http_user_agent" "$request_time" "$gzip_ratio" "$ssl_protocol/$ssl_cipher" "$connection_requests/$connection" $bytes_sent  "$upstream_response_length" "$upstream_header_time" "$upstream_response_time" "$upstream_status" $geoip_country_code
```
	remote_addr — client's IP-address
	host — host value in header
	time_local — request time (UTC)
	request — initial request string
	status — HTTP answer code
	upstream_cache_status — object status. For example HIT for object from cache, MISS for object from upstream service
	upstream_addr — upstream server address if object isn't presented in cache
	body_bytes_sent — size of HTTP reply (bytes)
	http_referer — value of Referer header
	http_user_agent — value of User-Agent header
	request_time — time of request processing
	gzip_ratio — compress ratio
	ssl_protocol/ssl_cipher — SSL/TLS version
	connection_requests/connection - index number of request for established connection
	bytes_sent — count of sent bytes include HTTP header
	upstream_response_length — size of recieved answer from upstream server
	upstream_header_time — time of recieving answer headers from upstream server
	upstream_response_time — time of recieving object upstream server
	upstream_status — HTTP answer code from upstream server
	geoip_country_code — country code of client IP

Solve these tasks:
1. Determine TOP-5 IP-addresses by requests.
2. Determine IP-address, which most often recieved 404 HTTP status.
3. Determine the most active hour by requests самый активный час (по количеству запросов).

#### Answer:
1. `awk '{print $1}' nginx-access.log | sort | uniq -c | sort -r`
2. `awk '{print $8,$1}' nginx-access.log | grep 404 | awk '{print $2}' |  uniq -c | sort -r | head -1`
3. `awk '{print $3}' nginx-access.log | sed 's/\[04\/Jun\/2018\://g' | grep -oE '^\d{2}' | sort | uniq -c | sort -r | head -1`


### Question №3

You have arbitrary finite sequence "[" and "]".
Describe algorithm which determine that in the sequence all brackets closed correctly.

#### Answer:
[brackets.cpp](brackets.cpp)
