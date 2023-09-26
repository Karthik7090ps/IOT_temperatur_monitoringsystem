#include <pgmspace.h>
 
#define SECRET
 
const char WIFI_SSID[] = "Iphone";               //TAMIM2.4G
const char WIFI_PASSWORD[] = "karthikp";           //0544287380
 
#define THINGNAME "**************"
 
int8_t TIME_ZONE = -5; //NYC(USA): -5 UTC
 
const char MQTT_HOST[] = "******************************";
 
 
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
 
-----END CERTIFICATE-----
)EOF";
 
 
// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUCEkPvo2jsOB43mq57H164hQYsVcwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDYyNzE2MTY1
MFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN5PLhZCi45FUifkpmrf
haQ1To+2SiklLEZ1fNWrcXieJNdf7xXvb8fXJzazyzI7yHtOYhaEZDddS/PLO8c/
WSHeVjMbbwr03BlBs/t0Nc7Y7LZod1MV6JKHo6zZYVx1qih1O33yNUJO0MQpW9Mi
xBlu0f74HcajokIY9wtu1oiQwUShXv6BSfCpiDhOChZZr8IvePSVWFc9f8YI6kni
h4pAAAA8YrswtOahUkg7WwK43endadpQDyiQCToZRZSPaCaURnAuV2eOnFgp1X1m
PoI5xg+fLNIoeoyxunZAhOlqTH/yjwDkhnLCOd3Dep9vrOtfPaChCb1UXXvubnDG
SnsCAwEAAaNgMF4wHwYDVR0jBBgwFoAUT+huaK6ZXic3bYvOnMYi0nV7eDAwHQYD
VR0OBBYEFDCMg4FwcmGeKGtVigLY7FYWi9Q0MAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCD5kX2IMPczzAwkH8Om5VAryq+
d0DUcXiN/4wNRy1jvo0fwjjg6pYkT2Dt57dakvH26jOeUpi+gr2aGz+MmX99/KEy
T2fSWPqgRoZPEHKau2lly0lLNF4id4RWIXap/9srSb09OqohwdfLK+v70g3y/QBH
dZZbmtwQux4PToAt1DcfYTWIZ8KjBqC/6mlGIBgKd6z2OjBSz2+4MSue3OMwiJTa
VTYOcPMWgsdzkjH+H3d/jUEU4+yLQF7WAPDGABazrudrEFWXHTJReYExQcjSpCSr
KHC6NwvtqDDm7+3zXbN4tp4oc3uFHGBJ3KiI7g7CC8HPIhYcrX6ptK9jBFrq
-----END CERTIFICATE-----

)KEY";
 
 
// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEA3k8uFkKLjkVSJ+Smat+FpDVOj7ZKKSUsRnV81atxeJ4k11/v
Fe9vx9cnNrPLMjvIe05iFoRkN11L88s7xz9ZId5WMxtvCvTcGUGz+3Q1ztjstmh3
UxXokoejrNlhXHWqKHU7ffI1Qk7QxClb0yLEGW7R/vgdxqOiQhj3C27WiJDBRKFe
/oFJ8KmIOE4KFlmvwi949JVYVz1/xgjqSeKHikAAADxiuzC05qFSSDtbArjd6d1p
2lAPKJAJOhlFlI9oJpRGcC5XZ46cWCnVfWY+gjnGD58s0ih6jLG6dkCE6WpMf/KP
AOSGcsI53cN6n2+s6189oKEJvVRde+5ucMZKewIDAQABAoIBAE/tsglI1bpKTDaR
rA/i277ld6CODu3qMpgGp+J+6KZQXbieAm0lkFAOmEe/rwAZpIRI81VbNlj9j1BR
MuX5bceSk/V+GJec4AGosNhouOvs7HbM6pIR33PHlt6PrcS7fXlcZQ5sZh+4DLFq
mVw5NL5cLN56QOJpdO5E4ZXXvQSOM4uGXmmw6Q+R7Z9zjk0lmgZ+26BYmk0Wl701
r3SLHTJakCTFM0LG3gCT6dZC+RQ7b41G9ssqmydAG50Jgx+srMORsV5Jm2w9FuBW
GywGutjKGK5GNmZRDBsFRDYhueorShQAsmqANfbGYWZEod1fCfGXJmDkETiLJeKc
ZKuepHkCgYEA8wkF7hd9BAr8WW4XJBCyxH+u9WIWTAVCoOJz1EHW1VZFiWOEjaDX
CuG0rShpMoa3m+iHNHp+MjpMr07FZp2Eo5VT4vzarPiGbtT1LD7IQhMAYTT/SDtI
xSbxyOphG2GRMUajGk55N/urs9I+my8R5YKkc6WdxhDSCy6K7IZlEjcCgYEA6isd
pxJ11NYIIJjEqT0NFjeHtz3WcigOF4GJXe4d6GahmOWarsMsFEIdNzTS9VqXTH4Z
VX/KJU+/UQqYIXx7X59suiY7j4NgJXUSOdxDEAGzKz8W9d53S9ZbLwj6XdSrLfCx
zrqVG6bxPBrnHnPz4RuO4stpG1wmuqtR78Fid90CgYBjttsJAfgYFY3N/35dHMDM
IHsfULxHOo1Ix0Cw4MaNR1VGdl9nYIt6enqP5RmsUlu5CyGWJX/ricH214HkhVJr
b5Q4eHgcKee2R4fEPIobmgI43+6xqylDQqRHQ+rNui1BI3M+Et5nWsnrAKMRNrHI
Ed75WAUww6v6TIFRZB7J5wKBgGHAiepanHGyv0XMQBxd7f6eQ7tMxx50dh1957gc
VMPVRBQtlPrrYpU6XDPVi1L89DfsU+sLI3mb5sOP5p3j9ySdyqeSmj54m0RHsMoS
lrQx4XdmKNGOgsJXw0zJNKrCwoq09aTU4rXeZMmweVaPFPmdpXIrc78GIuy948Bw
PAjJAoGAZBQ7RcZ5qRsA45pN2o2D5HiEW3a2SpMlsYXKaR6yo9MvT6nbCRQTCJzY
w+evoiIP9DBuJm0BC33w1uzI1w9WyKncWKvaOOJErdWhzNCmHO090twW/P2a14CU
p6cYq66D264jg5rJACPTi6hj72xyEwWfbC6re3vJwToXPzjkxwc=
-----END RSA PRIVATE KEY-----

)KEY";