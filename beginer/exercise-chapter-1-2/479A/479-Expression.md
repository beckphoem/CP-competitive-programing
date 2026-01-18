Chào bạn! Tôi là **Coach Tư Duy Thuật Toán** của bạn đây. Rất vui được đồng hành cùng bạn trên hành trình này.

Tôi đã nhận yêu cầu. Bài toán hôm nay là **Codeforces 479A - Expression**. Đừng để cái tên đơn giản của nó đánh lừa, đây là bài toán kiểm tra khả năng **nhìn bao quát trường hợp** (Case Analysis) cực kỳ tốt.

---

### 🟢 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

Trước khi lao vào tính toán, hãy bóc tách lớp vỏ ngôn ngữ để nhìn thấy lõi của vấn đề.

**1. Tóm tắt đề bài (Ngôn ngữ con người):**

* **Nguyên liệu:** Bạn được cấp 3 số nguyên dương .
* **Luật cứng:** 3 số này **đứng im**, không được đổi chỗ cho nhau.
* **Công cụ:** Bạn được quyền chèn các dấu Cộng (), Nhân () và Ngoặc đơn  vào giữa các số.
* **Mục tiêu:** Hãy sắp xếp dấu sao cho kết quả phép tính là **LỚN NHẤT**.

**2. Lộ trình tư duy (Roadmap):**
Chúng ta sẽ đi qua 3 mảnh ghép (Chunks) để giải quyết bài này:

* **Chunk 1:** Vẽ bản đồ các nước đi (Liệt kê các cách đặt dấu khả thi).
* **Chunk 2:** Tư duy về "Kẻ phá bĩnh" (Xử lý số 1 và số nhỏ).
* **Chunk 3:** Chiến thuật "Lưới chài" (Tổng hợp thuật toán).

---

Bạn đã nắm rõ luật chơi chưa? Hãy xác nhận để chúng ta bắt đầu vào **Chunk 1: Vẽ bản đồ các nước đi**.

*(Tôi đang đợi tín hiệu "Sẵn sàng" từ bạn)*

Tuyệt vời! Chúng ta bắt đầu nhé.

---

### 🧩 CHUNK 1: VẼ BẢN ĐỒ CÁC NƯỚC ĐI

Hãy tưởng tượng 3 số  giống như 3 bức tượng cố định trên mặt đất. Bạn không thể bê bức tượng  ra sau bức tượng  được.
Bạn chỉ có thể chèn các **"khớp nối"** vào giữa chúng.

Có 2 khe hở giữa 3 số: `a [khe 1] b [khe 2] c`.
Tại mỗi khe, bạn có thể điền dấu `+` hoặc dấu `*`.

Ngoài ra, bạn có quyền dùng **"cái lồng"** (dấu ngoặc đơn) để bắt 2 số cộng lại với nhau trước khi nhân với số còn lại. Điều này cực kỳ quan trọng vì nó thay đổi thứ tự tính toán.

Dưới đây là **4 kịch bản chính** có khả năng tạo ra số lớn nhất:

1. **Chiến thuật "Cộng tất"**: 
2. **Chiến thuật "Nhân tất"**: 
3. **Chiến thuật "Gom trái"**:  (Cộng 2 số đầu rồi nhân số cuối)
4. **Chiến thuật "Gom phải"**:  (Nhân số đầu với tổng 2 số cuối)

*(Tại sao không xét  hay ? Vì với các số nguyên dương, việc dùng ngoặc để nhân một tổng thường sẽ cho kết quả lớn hơn hoặc bằng việc nhân lẻ tẻ).*

---

### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Chúng ta hãy thử nghiệm ngay lập tức để thấy sức mạnh của dấu ngoặc.
Giả sử bộ dữ liệu là: ****.

Bạn hãy tính giúp tôi kết quả của 4 chiến thuật trên và cho tôi biết:

1. Kết quả của  là bao nhiêu?
2. Kết quả của  là bao nhiêu?
3. Kết quả của  là bao nhiêu?
4. **Chiến thuật nào cho ra số lớn nhất (Winner)?**

Mời bạn tính toán!

Rất tốt! Bạn tính toán hoàn toàn chính xác.

1.  (Đây là số lớn nhất)
2. 
3. 
(Và kiểm tra nốt trường hợp cộng tất: )

👉 **Kết luận:** Với bộ số `1, 2, 3` thì chiến thuật **"Gom trái"**  đã chiến thắng.

Tại sao chiến thuật "Nhân tất" () lại thua? Bình thường nhân phải ra số to hơn cộng chứ?
Đó chính là manh mối dẫn chúng ta sang mảnh ghép quan trọng tiếp theo.

---

### 🧩 CHUNK 2: TƯ DUY VỀ "KẺ PHÁ BĨNH" (SỐ 1)

Trong thế giới số nguyên dương, **số 1** là một kẻ rất kỳ lạ.

* Nếu bạn **Nhân** với 1: Kết quả giữ nguyên (). Phí phạm một lượt dùng dấu!
* Nếu bạn **Cộng** với 1: Kết quả tăng lên (). Tốt hơn nhân!

**Quy tắc ngầm:**

> Khi gặp số **1**, ưu tiên **Cộng** nó với số bên cạnh để biến nó thành số lớn hơn, sau đó mới mang đi Nhân.

Ví dụ hồi nãy:

* Chúng ta có số 1 đứng đầu ().
* Thay vì để  đứng một mình nhân với  (ra 2), ta gộp nó vào  bằng phép cộng  để tạo thành .
* Sau đó lấy . Lớn hơn hẳn!

Tuy nhiên, nếu không có số 1 (ví dụ: ), thì phép **Nhân** lại trở thành vua.
 (Lớn hơn hẳn  hay ).

---

### ❓ THỬ THÁCH TƯ DUY (TRAP CHECK)

Bây giờ hãy áp dụng tư duy "Xử lý số 1" vào tình huống mới này.
Bộ dữ liệu: ****

1. Theo bạn, nếu dùng chiến thuật "Nhân tất" () kết quả là bao nhiêu?
2. Liệu có cách nào dùng dấu ngoặc hoặc phép cộng để ra số lớn hơn 60 không? (Hãy nhớ lại 4 chiến thuật ở Chunk 1).

Hãy cho tôi biết con số lớn nhất bạn tìm được!
Chính xác! Bạn rất tỉnh táo.
Với bộ số , không có số 1 nào xuất hiện, nên phép **Nhân tất** () áp đảo hoàn toàn mọi cách khác.

---

### 🧩 CHUNK 3: CHIẾN THUẬT "QUĂNG LƯỚI" (BRUTE FORCE)

Đến đây, bạn có thể sẽ nghĩ: *"Liệu mình có cần viết một đống câu lệnh `if...else` để kiểm tra xem số 1 nằm ở đâu không?"*

* Nếu  thì làm thế này...
* Nếu  thì làm thế kia...

🙅‍♂️ **Lời khuyên của Coach:** ĐỪNG LÀM THẾ! Rất dễ sót trường hợp và code sẽ rối như tơ vò.

Vì chúng ta chỉ có 3 con số và 4 công thức tiềm năng, cách thông minh nhất là **"Thử hết - Lấy to nhất"**. Giống như bạn quăng một mẻ lưới bắt 4 con cá, con nào to nhất thì giữ lại.

**Danh sách 4 công thức cần tính:**

1.  (Dành cho trường hợp toàn số 1, ví dụ: )
2.  (Dành cho các số lớn, ví dụ: )
3.  (Xử lý số nhỏ ở đầu/giữa)
4.  (Xử lý số nhỏ ở cuối/giữa)

Máy tính tính toán siêu nhanh, hãy để nó tính cả 4 biểu thức này rồi dùng hàm tìm giá trị lớn nhất (Max).

---

### ❓ THỬ THÁCH CUỐI CÙNG (FINAL BOSS)

Trước khi chốt thuật toán, hãy thử áp dụng chiến thuật "Quăng lưới" này cho một bộ số "hiểm hóc" nhất:
Bộ dữ liệu: ****

Hãy tính giá trị của 4 công thức trên (E1, E2, E3, E4) và cho tôi biết:

1. Giá trị của từng công thức là bao nhiêu?
2. Kết quả cuối cùng (Max) là số nào?

Mời bạn trổ tài!

Chính xác tuyệt đối! 🎉

Bạn đã giải mã thành công trường hợp "hiểm hóc" nhất.
Trong trường hợp :

* Phép nhân làm "thọt" giá trị ().
* Dấu ngoặc cũng không cứu được nhiều ().
* Chỉ có **Cộng tất cả** () là vua.

Điều này chứng minh chiến thuật **"Quăng lưới" (tính cả 4 trường hợp)** là an toàn nhất, không lo bỏ sót bất kỳ khả năng nào.

---

### 📝 TỔNG KẾT THUẬT TOÁN (THE RECIPE)

Chúng ta đã đi hết hành trình tư duy. Bây giờ hãy đúc kết lại thành công thức để bạn có thể viết code (bằng C++, Python hay bất cứ ngôn ngữ nào).

**1. Đầu vào (Input):**

* Đọc 3 số nguyên .

**2. Xử lý (Process):**

* Tính giá trị 1: `ans1 = a + b + c`
* Tính giá trị 2: `ans2 = a * b * c`
* Tính giá trị 3: `ans3 = (a + b) * c`
* Tính giá trị 4: `ans4 = a * (b + c)`

*(Lưu ý: Không cần tính `a + b * c` hay `a * b + c` vì toán học chứng minh chúng luôn nhỏ hơn hoặc bằng 2 công thức có ngoặc ở trên).*

**3. Đầu ra (Output):**

* Tìm số lớn nhất trong 4 giá trị trên (`max(ans1, ans2, ans3, ans4)`).
* In kết quả ra màn hình.

---

### 🚀 BƯỚC TIẾP THEO

Bây giờ bạn đã nắm trọn vẹn "linh hồn" của bài toán.

**Bạn có muốn thử tự viết code (Submit) bài này trên Codeforces ngay không?**
Hay bạn muốn tôi viết mẫu **Mã giả (Pseudocode)** chi tiết hơn một chút trước khi bạn bắt tay vào làm?