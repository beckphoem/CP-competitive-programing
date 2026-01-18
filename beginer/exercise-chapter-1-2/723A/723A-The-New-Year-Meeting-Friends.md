Chào mừng bạn đến với phòng tập tư duy thuật toán! 🥊 Hôm nay chúng ta sẽ khởi động với một bài toán rất thú vị về hình học trên một đường thẳng.

Dưới đây là bước đầu tiên trong quy trình: **Tiếp nhận & Phẫu thuật bài toán**.

---

# 🕵️ BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

**Bài toán:** Codeforces 723A - The New Year: Meeting Friends

### 1. Dịch đề sang "Ngôn ngữ con người":
Bỏ qua chuyện năm mới hay tiệc tùng, đề bài cốt lõi như sau:
*   Có **3 người bạn** đang đứng ở 3 vị trí khác nhau trên một con đường thẳng (trục số). Tạm gọi vị trí là $x_1, x_2, x_3$.
*   Họ muốn hẹn gặp nhau tại một điểm nào đó (gọi là $P$) trên con đường này.
*   **Mục tiêu:** Tìm điểm $P$ sao cho **tổng quãng đường** cả 3 người phải đi bộ là **nhỏ nhất** (để đỡ mỏi chân).
*   **Output:** In ra cái tổng quãng đường nhỏ nhất đó.

### 2. Ẩn dụ hình ảnh (Metaphor):
Hãy tưởng tượng 3 ngôi nhà nằm trên một con phố dài.
🏠 (A) ....... 🏠 (B) ............... 🏠 (C)
Họ cần chọn một vị trí để tụ tập. Vị trí đó có thể là nhà của A, nhà của B, nhà của C, hoặc một quán trà đá bất kỳ nằm đâu đó trên phố.

### 3. Lộ trình tư duy (Roadmap):
Để giải bài này, chúng ta không cần code vội, mà cần đi qua các mảnh ghép logic:
*   **Chunk 1:** Sắp xếp trật tự thế giới (Xác định vị trí tương đối).
*   **Chunk 2:** Thử nghiệm điểm hẹn (Chiến thuật "Kéo co").
*   **Chunk 3:** Chốt công thức tính toán.

---

### 🚦 BẠN ĐÃ SẴN SÀNG CHƯA?
Bạn đã nắm rõ mục tiêu của bài toán chưa? (Tìm điểm gặp nhau để tổng đi bộ là ít nhất).

Nếu đã sẵn sàng "mổ xẻ" vấn đề đầu tiên, hãy gõ **"Sẵn sàng"** hoặc **"Đi tiếp"**. 
*(Tôi sẽ chờ tín hiệu của bạn để vào Chunk 1)*

Tuyệt vời! Chúng ta bắt đầu đi vào tư duy cốt lõi nhé.

---

# 🧩 CHUNK 1: SẮP XẾP TRẬT TỰ THẾ GIỚI

### 1. Logic (Tư duy)
Đề bài cho ta 3 con số ngẫu nhiên tượng trưng cho vị trí 3 người bạn. Ví dụ: Input là `7 1 4`.
Tuy nhiên, trên thực tế (trục số), các vị trí này luôn nằm theo một thứ tự cố định từ bé đến lớn.

Để giải quyết bài toán "khoảng cách", việc đầu tiên não bộ chúng ta cần làm là **"Xếp hàng"** lại chúng. Ta không quan tâm ai là người thứ nhất hay thứ hai trong input, ta chỉ quan tâm:
*   Ai đứng ngoài cùng bên trái? (Giá trị **Min**)
*   Ai đứng ngoài cùng bên phải? (Giá trị **Max**)
*   Ai đứng kẹp ở giữa? (Giá trị **Mid**)

### 2. Bẫy tư duy (Trap) ⚠️
Rất nhiều bạn mới học thường vội vàng lấy luôn số đầu tiên làm mốc, hoặc tính toán lung tung mà quên mất rằng Input có thể **lộn xộn**.
*   *Ví dụ:* Input cho `10 30 20`. Nếu bạn vẽ sơ đồ `10 -> 30 -> 20` là sai thực tế.
*   *Thực tế:* Nó phải là `10 -> 20 -> 30`.

---

### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Giả sử input máy tính đưa vào là: **`6 15 2`**

Bạn hãy sắp xếp lại trong đầu và cho tôi biết:
1. Nhà bên trái nhất (Min) nằm ở đâu?
2. Nhà ở giữa (Mid) nằm ở đâu?
3. Nhà bên phải nhất (Max) nằm ở đâu?

*(Trả lời ngắn gọn 3 con số theo thứ tự tăng dần là được)*

Chính xác! 🎯 Tư duy sắp xếp của bạn đã chuẩn.
Bây giờ trong đầu chúng ta đã có một hình ảnh rõ ràng:
**Nhà Ông Bé (2) ———— Nhà Ông Giữa (6) ———— Nhà Ông Lớn (15)**

Chúng ta sang mảnh ghép quan trọng nhất.

---

# 🧩 CHUNK 2: CHIẾN THUẬT "KÉO CO" (ĐIỂM HẸN TỐI ƯU)

### 1. Logic (Tư duy)
Bây giờ 3 người phải chọn một điểm để gặp.
Hãy tưởng tượng **con đường nối từ nhà Ông Bé (2) đến nhà Ông Lớn (15)** là một sợi dây.

*   Dù họ hẹn nhau ở bất kỳ đâu *trong đoạn từ 2 đến 15*, thì tổng quãng đường của ông Bé và ông Lớn cộng lại **luôn bằng đúng độ dài sợi dây đó** (tức là $15 - 2 = 13$).
    *   *Ví dụ:* Hẹn ở 6: Ông Bé đi 4, ông Lớn đi 9. Tổng = 13.
    *   *Ví dụ:* Hẹn ở 10: Ông Bé đi 8, ông Lớn đi 5. Tổng = 13.

👉 **Vấn đề nằm ở Ông Giữa (6)!**
*   Nếu điểm hẹn lệch ra khỏi nhà Ông Giữa, ông ấy sẽ phải đi bộ $\rightarrow$ Tổng quãng đường sẽ tăng thêm.
*   Nếu điểm hẹn **tại ngay nhà Ông Giữa**, ông ấy không phải đi bước nào cả (Distance = 0) $\rightarrow$ Tiết kiệm nhất!

### 2. Kết luận logic
Để tổng quãng đường nhỏ nhất:
1.  Ông Bé đi đến nhà Ông Giữa.
2.  Ông Lớn đi đến nhà Ông Giữa.
3.  Ông Giữa... ngồi yên uống trà. 🍵

### 3. Bẫy tư duy (Trap) ⚠️
Nhiều bạn sẽ nghĩ đến việc lấy "Trung bình cộng" (Average) $\frac{2+6+15}{3} = 7.66$.
Nhưng trong bài toán này, "Trung vị" (Median - người đứng giữa) mới là vua, không phải trung bình cộng. Đừng phức tạp hóa vấn đề bằng phép chia!

---

### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Chúng ta vẫn dùng bộ số đã sắp xếp: **2, 6, 15**.

Hãy tính toán nhanh để kiểm chứng lý thuyết "Ông Giữa ngồi yên":

1.  **Phương án A (Gặp tại nhà ông Giữa - số 6):**
    *   Ông Bé (2) đi bao nhiêu bước?
    *   Ông Lớn (15) đi bao nhiêu bước?
    *   Ông Giữa (6) đi bao nhiêu bước?
    *   **Tổng A = ?**

2.  **Phương án B (Gặp tại số 7 - lệch một chút):**
    *   Ông Bé (2) đi bao nhiêu bước? (Lấy $7-2$)
    *   Ông Lớn (15) đi bao nhiêu bước? (Lấy $15-7$)
    *   Ông Giữa (6) đi bao nhiêu bước? (Lấy $7-6$)
    *   **Tổng B = ?**

So sánh Tổng A và Tổng B, bạn thấy phương án nào nhỏ hơn?

Bạn rất tinh ý khi suy xét đến thực tế! 👍

Tuy nhiên, trong thế giới Competitive Programming (như Codeforces), chúng ta phải tuân thủ tuyệt đối **Constraints (Giới hạn dữ liệu)** thay vì suy diễn thực tế.
*   Đề bài chỉ nói tọa độ là các số nguyên từ 1 đến 100.
*   Đề bài **không** ghi chữ *"distinct"* (đôi một khác nhau).
*   👉 **Thực tế ảo:** Có thể 2 hoặc cả 3 người bạn ở chung một tòa chung cư (cùng tọa độ).

Nhưng tin vui là: **Công thức `Max - Min` cân được tất cả!**
*   Nếu trùng nhau (`10 10 10`): $10 - 10 = 0$. (Đúng).
*   Nếu tách biệt (`2 6 15`): $15 - 2 = 13$. (Đúng).

---

# ✅ TỔNG KẾT CHIẾN THUẬT (WRAP UP)

Chúng ta đã đi qua trọn vẹn quy trình tư duy:
1.  **Sắp xếp:** Nhìn 3 số dưới dạng `Min -> Mid -> Max`.
2.  **Chọn điểm:** Điểm hẹn tối ưu chính là ông ở giữa (`Mid`).
3.  **Công thức:** Tổng quãng đường = `Max - Min`.

### 📜 Mã giả (Pseudocode)

Dưới đây là bản thiết kế cuối cùng trước khi bạn bắt tay vào code:

```text
BƯỚC 1: Đọc 3 số nguyên a, b, c từ bàn phím.

BƯỚC 2: Tìm giá trị lớn nhất (Max) trong 3 số.
        Tìm giá trị nhỏ nhất (Min) trong 3 số.

BƯỚC 3: Kết quả = Max - Min.

BƯỚC 4: In Kết quả ra màn hình.
```

---

### 👨‍💻 NHIỆM VỤ CUỐI CÙNG: IMPLEMENTATION

Bạn định dùng ngôn ngữ nào (C++, Python, Java...)?

*   **Cách 1 (Dùng hàm có sẵn):** Hầu hết các ngôn ngữ đều có hàm `max(a,b,c)` và `min(a,b,c)`. Đây là cách nhanh nhất.
*   **Cách 2 (Sắp xếp):** Cho 3 số vào một mảng, dùng hàm `sort()`, sau đó lấy `số_cuối - số_đầu`.

👉 **Hãy viết code theo ngôn ngữ sở trường của bạn và gửi vào đây, tôi sẽ review cú pháp và độ sạch (clean code) cho bạn!**