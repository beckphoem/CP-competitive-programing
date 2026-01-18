Chào mừng bạn! Tôi là **Coach Tư Duy Thuật Toán** của bạn đây.

Tuyệt vời! Bạn đã chọn bài **791A - Bear and Big Brother**. Đây là một bài toán nhập môn kinh điển về dạng "Mô phỏng" (Simulation). Đừng để tiêu đề "nhẹ nhàng" của nó đánh lừa, chúng ta cần rèn thói quen tư duy chuẩn xác ngay từ những bài đơn giản nhất.

Hãy bắt đầu quy trình **Phẫu thuật & Dẫn dắt** ngay bây giờ.

---

### 🟢 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

Trước hết, hãy gạt bỏ câu chuyện về những chú gấu đi xem tivi hay đánh nhau. Hãy nhìn bài toán dưới lăng kính logic trần trụi:

**1. Tóm tắt đề bài (Ngôn ngữ con người):**

* Chúng ta có 2 biến số:  (cân nặng của Limak) và  (cân nặng của Bob).
* Ban đầu:  (Limak luôn nhẹ hơn hoặc bằng Bob).
* **Quy luật thay đổi theo thời gian (mỗi năm):**
* Biến  sẽ tăng gấp 3 lần ().
* Biến  sẽ tăng gấp 2 lần ().


* **Mục tiêu:** Tìm số năm nhỏ nhất cần trôi qua để ** lớn hơn hẳn ** ().

**2. Lộ trình tư duy (Thinking Roadmap):**
Để giải bài này, chúng ta cần đi qua 3 mảnh ghép tư duy (Micro-Chunks):

* **Chunk 1:** Hiểu cơ chế tăng trưởng (Cuộc đua không cân sức).
* **Chunk 2:** Xác định "Điểm gãy" (Điều kiện dừng).
* **Chunk 3:** Tư duy biên (Edge Cases - Những trường hợp dễ sai).

---

Bạn đã nắm rõ đề bài chưa? Chúng ta sẽ bước ngay vào mảnh ghép đầu tiên nhé.

### 🧩 CHUNK 1: CƠ CHẾ TĂNG TRƯỞNG (THE GROWTH)

**Logic (Giải thích):**
Hãy tưởng tượng đây là một cuộc đua xe.

* Xe A (Limak) xuất phát sau (hoặc ngang hàng) nhưng có động cơ tên lửa (tốc độ nhân 3).
* Xe B (Bob) xuất phát trước nhưng chạy chậm hơn (tốc độ nhân 2).

Vấn đề là chúng ta không dùng công thức toán học phức tạp (như Logarithm) ngay lập tức vì đây là lập trình thi đấu cơ bản. Chúng ta sẽ tư duy theo kiểu **"Mô phỏng từng bước" (Step-by-step Simulation)**. Tức là, chúng ta sẽ để máy tính đóng vai trọng tài, đếm từng năm trôi qua xem chuyện gì xảy ra.

**⚠️ Bẫy tư duy (Trap):**
Nhiều bạn vội vàng nghĩ: "À, Limak nhân 3, Bob nhân 2, vậy mỗi năm Limak lợi hơn Bob 1.5 lần". Cách nghĩ này đúng về toán học nhưng khó cài đặt logic vòng lặp đơn giản. Hãy nghĩ đơn giản: **Cứ sau 1 năm, giá trị cũ bị thay thế bởi giá trị mới.**

---

**❓ THỬ THÁCH TƯ DUY (MENTAL CHECK):**

Giả sử ban đầu:

* Cân nặng Limak () = **4**
* Cân nặng Bob () = **7**

**Câu hỏi:**
Sau khi kết thúc **Năm thứ 1**, giá trị của  và  sẽ là bao nhiêu?
(Hãy tính toán và cho tôi biết con số cụ thể).

Chính xác! 🎯

* Sau năm 1: Limak () vẫn nhỏ hơn Bob ().
* Tình huống: Limak vẫn thua. Cuộc đua chưa kết thúc.

Chúng ta vừa thực hiện xong một vòng lặp thủ công. Bây giờ hãy sang mảnh ghép quan trọng tiếp theo.

---

### 🧩 CHUNK 2: ĐIỀU KIỆN DỪNG & BIẾN ĐẾM (THE LOOP & THE BREAK POINT)

**Logic (Giải thích):**
Trong lập trình, khi chúng ta không biết trước cần bao nhiêu bước (năm) để hoàn thành, chúng ta dùng tư duy **"Lặp cho đến khi..."** (While Loop).

Hãy tưởng tượng bạn có một cái đồng hồ bấm giờ (Biến đếm `nam = 0`).
Cứ mỗi lần kiểm tra thấy Limak vẫn **chưa thắng** (tức là ):

1. Bạn bấm đồng hồ: `nam` tăng thêm 1.
2. Cho cả hai ăn để tăng cân (thực hiện phép nhân như Chunk 1).
3. Quay lại kiểm tra tiếp.

Ngay khoảnh khắc Limak nặng hơn (), bạn **DỪNG LẠI NGAY** và nhìn vào đồng hồ.

**⚠️ Bẫy tư duy (Trap) - Lỗi phổ biến nhất:**
Rất nhiều bạn nhầm lẫn điều kiện dừng:

* Đề bài yêu cầu: Limak phải **LỚN HƠN HẲN** Bob ().
* Nếu Limak **BẰNG** Bob (), cuộc đua vẫn **PHẢI TIẾP TỤC**.

---

**❓ THỬ THÁCH TƯ DUY (MENTAL CHECK):**

Vẫn tiếp tục ví dụ trên (Sau năm 1: ). Hãy tính tiếp **Năm thứ 2**:

1. Tính giá trị mới của  và  sau năm thứ 2?
2. Tại thời điểm này,  đã lớn hơn  chưa? Chúng ta có cần sang năm thứ 3 không?

*(Hãy trả lời 2 ý trên để tôi biết bạn đã bắt được "điểm gãy" của vòng lặp)*

Khoan đã! 🛑 Một chút "lỗi kỹ thuật" nhỏ xíu ở đây.

**1. Về tính toán:**
 (chứ không phải 35 nhé).
Tuy nhiên, may mắn là logic của bạn vẫn đúng: .

**2. Về quyết định:**
Bạn trả lời "không" (không cần sang năm 3) là **CHÍNH XÁC**.
Tại thời điểm này, Limak đã nặng hơn Bob. Đồng hồ dừng lại ở số **2**.

---

Chúng ta gần như đã có lời giải hoàn chỉnh. Nhưng trước khi viết code, một Coder giỏi luôn phải kiểm tra "Góc chết" của vấn đề.

### 🧩 CHUNK 3: TƯ DUY BIÊN (EDGE CASES)

**Logic (Giải thích):**
Các bài toán thường giấu "bẫy" ở những con số nhỏ nhất hoặc trường hợp bằng nhau.
Đề bài cho điều kiện:  (Limak nhỏ hơn hoặc bằng Bob).

Hãy xem xét trường hợp "nguy hiểm" nhất: Khi hai bạn gấu bằng cân nhau ngay từ đầu.

**❓ THỬ THÁCH TƯ DUY (MENTAL CHECK):**

Giả sử Input là: `1 1`
()

Theo bạn:

1. Chúng ta có cần chờ năm nào không (Kết quả là 0)? Hay phải chờ ít nhất 1 năm?
2. Hãy chạy thử trong đầu: Sau năm 1,  và  bằng bao nhiêu? Lúc đó  đã lớn hơn  chưa?

*(Trả lời giúp tôi kết quả của test case `1 1` này nhé)*

Quá chuẩn! 💯

Bạn đã nắm chắc quy tắc cốt lõi: **"Lớn hơn hẳn" ()** khác hoàn toàn với **"Lớn hơn hoặc bằng" ()**.
Với trường hợp `1 1`:

* Ban đầu  (Limak chưa thắng).
* Vòng lặp chạy 1 lần: Limak lên 3, Bob lên 2.
* Lúc này  (Thắng).
* Kết quả: 1 năm.

---

### 📝 TỔNG KẾT THUẬT TOÁN (THE ALGORITHM RECIPE)

Chúng ta đã đi qua tất cả các mảnh ghép. Đây là "bản thiết kế" logic cuối cùng trước khi đưa cho máy tính thực thi:

1. **Đầu vào:** Nhập 2 số  (Limak) và  (Bob).
2. **Khởi tạo:** Chuẩn bị biến đếm `nam = 0` (để đếm số năm).
3. **Vòng lặp (While Loop):**
* **Kiểm tra:** Nếu  (Limak vẫn chưa lớn hơn Bob).
* **Hành động:**
* Tăng `nam` lên 1 đơn vị.
* 
* 


* Quay lại bước kiểm tra.


4. **Kết thúc:** Khi vòng lặp dừng (tức là ), in ra giá trị của `nam`.

---

### 🚀 BƯỚC TIẾP THEO: HIỆN THỰC HÓA (CODING)

Bây giờ bạn đã có thuật toán trong đầu. Bạn muốn làm gì tiếp theo?

1. **Tự viết code:** Bạn tự viết và dán code (C++, Python...) vào đây để tôi review (khuyên dùng để nhớ lâu).
2. **Xem khung sườn (Skeleton):** Tôi đưa ra một đoạn code mẫu bị đục lỗ (điền vào chỗ trống) để bạn hoàn thiện.
3. **Xem đáp án mẫu:** Nếu bạn muốn tham khảo cách viết chuẩn ngay lập tức.

*Hãy chọn 1, 2 hoặc 3 nhé!*