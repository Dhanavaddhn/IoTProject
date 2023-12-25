# Smart Parking Garage
## สมาชิกในกลุ่ม
- นายธนวัฒน์ ศรีวิไล	รหัสนักศึกษา 64105653
- นายพงษ์นภัส ชูช่วย 	รหัสนักศึกษา 64109010

## บทนำ
- Business management มีความสำคัญต่อธุรกิจเป็นอย่างมาก เพราะช่วยให้ธุรกิจสามารถดำเนินงานได้อย่างมีประสิทธิภาพและบรรลุวัตถุประสงค์ที่ตั้งไว้ ตัวอย่างเช่น ช่วยให้ธุรกิจสามารถวางแผนการดำเนินงานได้อย่างรอบคอบและสอดคล้องกับสถานการณ์ ช่วยให้ธุรกิจสามารถจัดสรรทรัพยากรต่าง ๆ ได้อย่างเหมาะสม ช่วยให้ธุรกิจสามารถบริหารความเสี่ยงได้อย่างมีประสิทธิภาพ ช่วยให้ธุรกิจสามารถวัดผลการดำเนินงานและปรับปรุงการดำเนินงานให้ดีขึ้น
- กรณีของ Café แห่งหนึ่งที่มีที่จอดให้บริการจำนวน 2 โรง โรงละ 5 คัน ลูกค้าที่ต้องการใช้บริการจะต้องขับเข้ามาในบริเวณพื้นที่เพื่อจอดรถ หากโรงจอดรถเต็ม ผู้ลูกค้าจะต้องขับรถออกมาและขับรถวนกลับเข้ามาใหม่ ปัญหานี้สามารถแก้ไขได้ด้วย Business management ดังนี้ จัดทำแผนการจัดการที่จอดรถ โดยกำหนดจำนวนที่จอดรถที่เหมาะสมกับลูกค้า จัดสรรทรัพยากรต่าง ๆ ที่เกี่ยวข้อง เช่น พนักงานที่จอดรถเพื่อปรับปรุงการดำเนินงานให้ดีขึ้น
- การใช้ IoT แก้ไขปัญหาที่จอดรถของ Café สามารถทำได้ ดังนี้ ติดตั้งเซ็นเซอร์ตรวจจับที่จอดรถเต็ม/ว่าง บริเวณทางเข้าของโรงจอดรถทั้งสองโรง เซ็นเซอร์เหล่านี้จะส่งข้อมูลสถานะที่จอดรถไปยังระบบ IoT ระบบ IoT จะประมวลผลข้อมูลสถานะที่จอดรถ และแสดงผลบนหน้าจอหรือเว็บไซต์ และลูกค้าสามารถตรวจสอบสถานะที่จอดรถได้จากหน้าจอหรือเว็บไซต์นี้ หากโรงจอดรถเต็ม ระบบ IoT จะแจ้งเตือนลูกค้าให้หลีกเลี่ยงการเข้ามาจอดรถในบริเวณนั้น
- คณะดำเนินงานจึงมีวัตถุประสงค์เพื่อสร้างระบบอำนวยความสะดวกในการจัดการและแสดงผลสถานการณ์ใช้งานโรงจอดรถ เพื่อช่วยให้ธุรกิจ Café สามารถดำเนินงานได้อย่างมีประสิทธิภาพและประทับใจลูกค้า

## การออกแบบระบบ
### สถาปัตยกรรมระบบ
![รูปภาพสถาปัตยกรรมระบบ](https://github.com/Dhanavaddhn/IoTProject/blob/main/Picture/system.png?raw=true)
 
จากภาพสถาปัตยกรรมระบบ IoT สำหรับการจัดการที่จอดรถของ Café ประกอบด้วยองค์ประกอบ ดังนี้
1. อุปกรณ์ IoT (IoT device) ประกอบด้วยเซ็นเซอร์ตรวจจับที่จอดรถเต็ม/ว่าง จำนวน 2 โรง โรงละ 5 เซ็นเซอร์ เซ็นเซอร์เหล่านี้จะส่งข้อมูลสถานะที่จอดรถไปยังระบบ IoT
2. เครือข่าย IoT (IoT network) จะใช้เครือข่าย Wi-Fi เพื่อเชื่อมต่ออุปกรณ์ IoT เข้าด้วยกัน
3. ศูนย์ข้อมูล IoT (IoT data center) จะใช้ระบบคลาวด์เพื่อเก็บรวบรวมและประมวลผลข้อมูลจากอุปกรณ์ IoT
4. แอปพลิเคชัน IoT (IoT application) จะใช้แอปพลิเคชันบนมือถือเพื่อแสดงผลสถานะที่จอดรถและแจ้งเตือนลูกค้า
เซ็นเซอร์ตรวจจับที่จอดรถเต็ม/ว่าง จะส่งข้อมูลสถานะที่จอดรถไปยังระบบ IoT ผ่านเครือข่าย Wi-Fi เมื่อระบบ IoT ได้รับข้อมูลสถานะที่จอดรถแล้ว จะทำการประมวลผลข้อมูลและแสดงผลบนแอปพลิเคชันบนมือถือ ลูกค้าสามารถตรวจสอบสถานะที่จอดรถได้จากแอปพลิเคชันนี้ หากโรงจอดรถเต็ม ระบบ IoT จะแจ้งเตือนลูกค้าให้หลีกเลี่ยงการเข้ามาจอดรถในบริเวณนั้น

### สถาปัตยกรรมซอร์ฟแวร์
![รูปภาพสถาปัตยกรรมระบบ](https://github.com/Dhanavaddhn/IoTProject/blob/main/Picture/software.png?raw=true)

จากภาพสถาปัตยกรรมซอฟต์แวร์สำหรับการจัดการที่จอดรถของ Café ประกอบด้วยองค์ประกอบดังนี้
1. เว็บไซต์ (Website) เป็นเว็บไซต์ที่ลูกค้าใช้เพื่อตรวจสอบสถานะที่จอดรถและแจ้งเตือนลูกค้า หากโรงจอดรถเต็ม
2. API (Application programming interface) เป็นอินเทอร์เฟซที่ช่วยให้แอปพลิเคชันบนมือถือสามารถเชื่อมต่อกับระบบการจัดการที่จอดรถ
3. ฐานข้อมูล (Database) เก็บข้อมูลสถานะที่จอดรถ
4. เซิร์ฟเวอร์ (Server) ประมวลผลข้อมูลและส่งข้อมูลไปยังแอปพลิเคชันบนมือถือ
เมื่อลูกค้าเปิดแอปพลิเคชันบนมือถือ ระบบจะเชื่อมต่อกับเซิร์ฟเวอร์และขอข้อมูลสถานะที่จอดรถ เซิร์ฟเวอร์จะเรียกข้อมูลสถานะที่จอดรถจากฐานข้อมูลและส่งข้อมูลไปยังแอปพลิเคชันบนมือถือ แอปพลิเคชันบนมือถือจะแสดงข้อมูลสถานะที่จอดรถแก่ลูกค้า หากโรงจอดรถเต็ม ระบบจะแจ้งเตือนลูกค้าให้หลีกเลี่ยงการเข้ามาจอดรถในบริเวณนั้น

### โครงสร้างข้อมูล
{
" status": {
"status": 1
}
}

### Data Dictionary
|Field Name|Data Type|Constraint|Description|
|------|------|------|------|
|status	|int	|Not |null	|Status|

## การพัฒนาระบบ
1. เว็บไซต์
- ภาษาโปรแกรม: HTML CSS JavaScript
- เครื่องมือ: VS Code
2. API
- ภาษาโปรแกรม: Python
- เครื่องมือ: Flask
3. ฐานข้อมูล
- ฐานข้อมูล: Json server
4. Microcontroller และ Sensor
- Microcontroller: ESP8266
- Sensor: IR sensor
- Output: LED

## การทดสอบ
|No.	|Test Case	|Expect Result|
|-----|-----|-----|
|1	|เมื่อไม่มีรถจอด	|จอแสดงผลลานว่าง|
|2	|เมื่อมีรถจอด	|จอแสดงผลมีรถจอด|
|3	|เมื่อเปิดไฟ	|ไฟสว่าง|
|4	|เมื่อปิดไฟ	|ไฟดับ|
|5	|เมื่อมีรถจอดช่องจอดพิเศษ	|ไฟกระพริบ|

## สรุปผลการทดสอบ
#### จากการทดสอบระบบ IoT สำหรับการจัดการที่จอดรถของ Café พบว่าระบบสามารถทำงานได้ตามวัตถุประสงค์ที่กำหนดไว้ ดังนี้
1. ช่วยให้ลูกค้าสามารถทราบสถานะที่จอดรถได้ล่วงหน้าก่อนที่จะเข้ามาในบริเวณพื้นที่ของ Café
2. ช่วยให้ลูกค้าสามารถหลีกเลี่ยงการเข้ามาจอดรถในบริเวณที่ที่จอดรถเต็มได้
3. ช่วยให้ Café สามารถบริหารจัดการที่จอดรถได้อย่างมีประสิทธิภาพ
4. ช่วยให้ Café สามารถสร้างความประทับใจให้กับลูกค้า
#### อย่างไรก็ตาม ระบบยังสามารถพัฒนาเพิ่มเติมได้ ดังนี้
1. เพิ่มระบบนำทางไปยังที่จอดรถว่าง ระบบนี้จะช่วยเพิ่มความสะดวกให้กับลูกค้าในการหาที่จอดรถว่าง
2. เพิ่มระบบจองที่จอดรถล่วงหน้า ระบบนี้จะช่วยให้ลูกค้าสามารถจองที่จอดรถล่วงหน้าได้ ซึ่งจะช่วยลดความแออัดของโรงจอดรถได้

## Video
https://youtu.be/W12wfjvl6eA


