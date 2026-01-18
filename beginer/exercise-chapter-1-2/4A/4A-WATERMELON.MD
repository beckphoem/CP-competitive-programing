Chào bạn, bài **4A - Watermelon (Dưa hấu)** trên Codeforces là một bài toán kinh điển dành cho người mới bắt đầu (bài "nhập môn"). Dù đề bài rất ngắn, nó chứa một "cái bẫy" nhỏ giúp rèn luyện tư duy cẩn thận.

Dưới đây là phần phân tích chi tiết dành cho học sinh cấp 2.

---

### 1. Dịch đề bài (Tiếng Việt)

**Cốt truyện:**
Hai người bạn (Pete và Billy) quyết định mua một quả dưa hấu. Họ chọn được một quả to và chín, cân nặng là  kg.

Họ muốn chia quả dưa này thành **2 phần** (không nhất thiết phải bằng nhau). Tuy nhiên, cả hai đều thích số chẵn, nên họ đặt ra một yêu cầu bắt buộc:

* **Yêu cầu:** Khối lượng của **cả hai phần** sau khi chia đều phải là **số chẵn** (ví dụ: 2kg, 4kg, 6kg...).
* **Dữ liệu vào:** Một số nguyên  () biểu thị cân nặng của quả dưa.
* **Dữ liệu ra:** In ra `YES` nếu có thể chia được như yêu cầu, ngược lại in ra `NO`.

---

### 2. Phân tích tư duy (Logic Toán học)

Để giải quyết bài này, chúng ta không cần code vội, hãy dùng toán học cơ bản lớp 6.

**Quy tắc cộng số chẵn lẻ:**
Bạn muốn chia số tổng  thành 2 phần: gọi là phần A và phần B.


Đề bài yêu cầu:

1.  phải là số chẵn.
2.  phải là số chẵn.
3.  và  đều phải lớn hơn 0 (vì là khối lượng của một phần quả dưa).

**Suy luận:**
Nếu bạn cộng hai số chẵn lại với nhau (), kết quả chắc chắn phải là một số **Chẵn**.

* Ví dụ: ; ; .

 **Điều kiện 1:** Để chia được thành 2 phần chẵn, thì tổng khối lượng  bắt buộc phải là **SỐ CHẴN**. Nếu  là số lẻ (như 3, 5, 7...), chắc chắn không thể chia được (vì Lẻ = Chẵn + Lẻ).

**Cái bẫy chết người (Edge Case):**
Rất nhiều bạn học sinh mới học lập trình chỉ kiểm tra xem  có chẵn hay không (chia hết cho 2). Nhưng hãy xem xét trường hợp đặc biệt: **Số 2**.

* Nếu quả dưa nặng kg.
* Số 2 là số chẵn (Thỏa mãn điều kiện 1).
* Tuy nhiên, để chia thành 2 phần dương, cách duy nhất là: .
* Số  là số lẻ.  **Không thỏa mãn yêu cầu**.

 **Điều kiện 2:** Số  phải lớn hơn 2.

---

### 3. Giải thích Test Case (Ví dụ)

Hãy cùng thử chạy "bằng tay" vài trường hợp để hiểu rõ hơn:

| Cân nặng () | Phân tích | Kết quả | Giải thích |
| --- | --- | --- | --- |
| **8** | Chẵn, lớn hơn 2 | **YES** | Có thể chia thành  hoặc . Cả 2 phần đều chẵn. |
| **5** | Lẻ | **NO** | Số lẻ không bao giờ tách được thành 2 số chẵn. |
| **100** | Chẵn, lớn hơn 2 | **YES** | Có thể chia thành , , v.v. |
| **2** | Chẵn, nhưng bằng 2 | **NO** | Chỉ chia được thành  (hai số lẻ). |

---

### 4. Tổng kết thuật toán

Để giải bài này, tư duy của bạn cần đi theo luồng sau:

1. **Nhập** số .
2. **Kiểm tra điều kiện:**
*  có chia hết cho 2 không? (Tức là  % 2 == 0)
* **VÀ**  có lớn hơn 2 không? (Tức là )


3. **Kết luận:**
* Nếu thỏa mãn **cả hai** điều trên  In `YES`.
* Nếu vi phạm bất kỳ điều nào  In `NO`.



> **Mẹo nhỏ cho người mới:** Trong lập trình thi đấu, các trường hợp biên (như số 0, số 1, số 2 hoặc số cực lớn) thường là nơi người ra đề "gài bẫy" thí sinh. Hãy luôn tự hỏi: "Số nhỏ nhất có thể chạy đúng không?".

Bạn có muốn tôi thử đưa ra một bài tập tương tự để bạn luyện tập tư duy biên (edge case) này không?