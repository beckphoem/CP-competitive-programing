Chào mừng bạn! Chúng ta sẽ cùng nhau "mổ xẻ" bài **Codeforces 151A - Soft Drinking**.

Đây là một bài toán kinh điển về **Quản lý tài nguyên** và **Tìm điểm thắt nút (Bottleneck)**. Đừng để đống biến số $n, k, l, c, d, p, nl, np$ làm bạn hoa mắt. Chúng ta sẽ dọn dẹp nó ngay bây giờ.

---

### 1. 🔪 PHẪU THUẬT ĐỀ BÀI (DECONSTRUCT)

Hãy quên chuyện "uống nước ngọt" đi. Hãy tưởng tượng bạn là một **Bar trưởng** đang pha chế các **Combo đồ uống**.

Để làm ra **1 Combo** hoàn chỉnh, bạn **BẮT BUỘC** phải có đủ 3 thành phần cùng lúc:
1.  **Nước:** Một lượng ml nhất định.
2.  **Chanh:** Một lát chanh.
3.  **Muối:** Một lượng gam muối.

Nếu thiếu bất kỳ cái nào trong 3 cái này $\rightarrow$ **Không thể tạo ra Combo**.

**Dữ liệu đầu vào (Input) thực chất là kho hàng của bạn:**
*   **Nhân lực:** $n$ (số người bạn).
*   **Kho Nước:** $k$ chai, mỗi chai $l$ ml.
*   **Kho Chanh:** $c$ quả, mỗi quả cắt được $d$ lát.
*   **Kho Muối:** $p$ gam.
*   **Công thức pha 1 Combo:** Cần $nl$ ml nước và $np$ gam muối (và luôn luôn là 1 lát chanh).

---

### 2. 🗺️ LỘ TRÌNH TƯ DUY

Chúng ta sẽ đi qua 3 mảnh ghép (Chunks):
1.  **Chunk 1: Tổng kiểm kê kho hàng** (Quy đổi mọi thứ về đơn vị nhỏ nhất).
2.  **Chunk 2: Quy tắc "Chiếc thùng gỗ"** (Tìm xem nguyên liệu nào sẽ hết trước).
3.  **Chunk 3: Chia phần công bằng** (Tính ra kết quả cuối cùng cho mỗi người).

---

### 🚀 BẮT ĐẦU: CHUNK 1 - TỔNG KIỂM KÊ

Trước khi pha chế, bạn phải biết trong kho mình có **tổng cộng** bao nhiêu nguyên liệu rời. Đề bài cho số lượng theo "gói" (chai, quả), ta cần đổi ra đơn vị sử dụng (ml, lát).

*   **Nước:** Bạn có $k$ chai, mỗi chai $l$ ml.
*   **Chanh:** Bạn có $c$ quả, mỗi quả cắt được $d$ lát.
*   **Muối:** Đã có sẵn $p$ gam (không cần tính).

👉 **Nhiệm vụ:** Tính tổng số lượng thực tế có thể dùng được.

#### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Giả sử kho hàng của bạn có số liệu sau:
*   $k = 3$ (chai), $l = 100$ (ml/chai).
*   $c = 5$ (quả chanh), $d = 2$ (lát/quả).
*   $p = 50$ (gam muối).

**Hỏi:**
Tổng số tài sản thực tế của bạn là bao nhiêu?
1.  Tổng lượng nước (ml) = ?
2.  Tổng số lát chanh = ?
3.  Tổng lượng muối = ?

*Hãy trả lời 3 con số này để tôi biết bạn đã nắm được bước "Kiểm kê".*

Chính xác về tư duy nhân (x)!

Tuy nhiên, lưu ý nhỏ ở mục 3:
*   Bạn trả lời `p / np` $\rightarrow$ Đây là bước **tính khả năng phục vụ** (đây chính là bước tiếp theo).
*   Còn bước **tổng kiểm kê** này đơn giản chỉ là $p$ (có bao nhiêu dùng bấy nhiêu).

Tóm lại, với số liệu ví dụ ở bước trước, trong kho ta đang có:
1.  Nước: $3 \times 100 = 300$ ml.
2.  Chanh: $5 \times 2 = 10$ lát.
3.  Muối: $50$ gam.

---

### 🚀 CHUNK 2: QUY TẮC "CHIẾC THÙNG GỖ" (BOTTLENECK)

Bây giờ bạn đã có tổng nguyên liệu. Chúng ta cần xem từng loại nguyên liệu **độc lập** có thể tạo ra tối đa bao nhiêu Combo.

Đây là lúc áp dụng công thức chia (/) mà bạn vừa nghĩ đến ở bước trước.

*   **Công thức pha 1 Combo cần:** $nl$ ml nước, $1$ lát chanh, $np$ gam muối.

**Nguyên lý:** Bạn chỉ có thể tạo ra số Combo bằng với nguyên liệu **ít nhất/hạn hẹp nhất** (giống như chiếc thùng gỗ được ghép từ các thanh gỗ dài ngắn khác nhau, nước trong thùng chỉ đựng được đến chiều cao của **thanh gỗ thấp nhất**).

#### ❓ THỬ THÁCH TƯ DUY (QUAN TRỌNG)

Vẫn dữ liệu cũ:
*   **Trong kho:** Nước **300**, Chanh **10**, Muối **50**.
*   **Công thức cần** ($nl, 1, np$): **5** ml nước, **1** lát chanh, **2** gam muối.

**Hỏi:**
1.  Nước đủ làm tối đa bao nhiêu combo? (300 / 5 = ?)
2.  Chanh đủ làm tối đa bao nhiêu combo? (10 / 1 = ?)
3.  Muối đủ làm tối đa bao nhiêu combo? (50 / 2 = ?)

👉 **Và chốt hạ:** Số Combo tối đa thực sự bạn có thể pha được (cho cả nhóm) là con số nào trong 3 con số trên? Tại sao?

Tuyệt vời! Bạn tính toán rất chuẩn.

1.  Nước đủ cho **60** ly.
2.  Chanh đủ cho **10** ly.
3.  Muối đủ cho **25** ly.

👉 **QUY LUẬT CỐT LÕI:**
Khi pha chế, chỉ cần **một** nguyên liệu hết là ta phải dừng lại ngay.
Ở đây, dù nước còn nhiều ê hề (đủ 60 ly), muối còn kha khá (25 ly), nhưng mới làm đến **ly thứ 10** thì chanh đã hết sạch!

$\rightarrow$ Số Combo tối đa làm được (cho toàn bộ nhóm) chính là số **nhỏ nhất** trong 3 số trên: **10 Combo**.

*(Đây chính là hàm `min(a, b, c)` trong lập trình).*

---

### 🚀 CHUNK 3: CHIA PHẦN CÔNG BẰNG (FINAL STEP)

Chúng ta đã có **10 Combo** trên bàn.
Nhưng đề bài không hỏi "làm được bao nhiêu ly tổng cộng", mà hỏi: **"Mỗi người bạn nhận được bao nhiêu ly?"**

Dữ kiện cuối cùng cần dùng:
*   Số người bạn: $n$.

Quy tắc chia: Phải chia đều. Nếu chia không hết thì bỏ phần dư (chia lấy phần nguyên), vì không thể uống "nửa ly" trong bài toán này (số nguyên).

#### ❓ THỬ THÁCH VỀ ĐÍCH

Vẫn ví dụ trên, ta có tổng **10 Combo**.
Giả sử nhóm bạn có $n = 3$ người.

**Hỏi:**
1.  Mỗi người được uống bao nhiêu ly?
2.  Nếu nhóm có $n = 4$ người, mỗi người uống mấy ly?
3.  Nếu nhóm có $n = 11$ người (đông hơn số ly), mỗi người uống mấy ly?

*Hãy cho tôi 3 kết quả cuối cùng này để hoàn tất bài toán.*

Chính xác tuyệt đối! 💯
Đặc biệt là trường hợp số 3 (10/11 = 0), bạn đã xử lý rất tốt việc số nguyên chia nhau sẽ mất phần thập phân (trong C++/Python/Java đều vậy).

---

### 📝 TỔNG KẾT CHIẾN THUẬT (WRAP-UP)

Chúng ta đã hoàn thành việc lắp ghép các mảnh tư duy. Đây là **Bản thiết kế thuật toán** cho bài 151A:

1.  **Bước 1: Quy đổi tổng lực**
    *   `Tổng_Nước` = $k \times l$
    *   `Tổng_Chanh` = $c \times d$
    *   `Tổng_Muối` = $p$

2.  **Bước 2: Tìm giới hạn (Bottleneck)**
    *   `Khả_năng_Nước` = `Tổng_Nước` / $nl$
    *   `Khả_năng_Chanh` = `Tổng_Chanh` / 1
    *   `Khả_năng_Muối` = `Tổng_Muối` / $np$
    *   👉 `Số_Combo_Tối_Đa` = **min**(`Khả_năng_Nước`, `Khả_năng_Chanh`, `Khả_năng_Muối`)

3.  **Bước 3: Chia phần**
    *   `Kết_quả` = `Số_Combo_Tối_Đa` / $n$

---

### 💻 GIAO NHIỆM VỤ CUỐI

Bây giờ là lúc bạn chuyển tư duy này thành code.

**Gợi ý nhỏ khi code:**
*   Hàm tìm giá trị nhỏ nhất:
    *   Trong **C++**: `min({a, b, c})` (lưu ý dùng ngoặc nhọn `{}` nếu so sánh 3 số trở lên trong thư viện `<algorithm>`) hoặc `min(a, min(b, c))`.
    *   Trong **Python**: `min(a, b, c)`.

Bạn hãy thử viết code và nộp bài (submit).
Nếu gặp lỗi (Compile Error, Wrong Answer...) hãy paste code vào đây, tôi sẽ giúp bạn "debug" tư duy!

Hoặc nếu bạn muốn tôi phân tích bài tiếp theo, hãy cho tôi biết tên bài. 🚀