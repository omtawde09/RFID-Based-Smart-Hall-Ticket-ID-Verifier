# RFID-Based Smart Hall Ticket / ID Verifier with Seat Allocation  

##  Project Overview  
This project is an **RFID-based verification and seat allocation system** designed for exam halls, events, or secured entry points.  
Each student/participant is issued an RFID card, which is scanned at the entrance.  
The system validates authenticity, displays details on an LCD, and allocates a seat number.  
Unauthorized cards are denied access.  

---

##  Objectives  
- Automate hall ticket/ID verification using RFID technology.  
- Allocate seat numbers securely and instantly.  
- Reduce manual verification errors and delays.  
- Prevent impersonation and unauthorized access.  
- Maintain an attendance log for admin monitoring.  

---

##  Components Used  
- Arduino Uno / Mega  
- RFID Reader (RC522 Module)  
- RFID Tags / Cards  
- 16x2 LCD Display  
- Buzzer (for alerts)  
- Resistors, Jumper Wires, Breadboard  

---

##  Working Principle  
1. Student scans RFID card at the reader.  
2. Arduino reads the UID and compares it with stored data.  
3. If valid → LCD displays **Name + Seat Number**.  
4. If invalid → LCD shows **Access Denied** with buzzer alert.  
5. Admin dashboard (optional) can display logs with **Name, Roll No, Time of Entry**.  

---

##  Features  
- Fast and reliable student verification.  
- Automatic seat number allocation.  
- Easy integration with admin dashboard.  
- Scalable for universities, events, and workplaces.  
- Low cost, easy to implement.  

---

##  Future Enhancements  
- Web-based dashboard for real-time monitoring.  
- Database integration (MySQL/Firebase).  
- QR/Barcode + RFID hybrid verification.  
- Cloud-based attendance system.  
