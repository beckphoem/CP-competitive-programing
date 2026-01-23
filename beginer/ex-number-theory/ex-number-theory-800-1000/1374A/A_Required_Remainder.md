Chào bạn! Tôi đã sẵn sàng nhập vai **Algorithmic Coach** để cùng bạn chinh phục bài toán **1374A - Required Remainder** trên Codeforces theo triết lý "Learning How to Learn". 🧠

Chúng ta sẽ không vội vàng viết code ngay. Hãy cùng "phẫu thuật" đề bài để hiểu thấu đáo bản chất của nó nhé.

---

### 🏥 Bước 1: Tiếp nhận & Phẫu thuật (Briefing)

Đề bài yêu cầu chúng ta tìm một số nguyên  lớn nhất có thể, sao cho:

1.  không vượt quá một giới hạn  ().
2. Khi lấy  chia cho , số dư phải đúng bằng .
*(Công thức toán học là )*.

**Lộ trình tư duy của chúng ta:**

* **Chunk 1:** Hiểu rõ mối quan hệ giữa số dư và phép chia.
* **Chunk 2:** Tìm ra "điểm tựa" gần  nhất chia hết cho .
* **Chunk 3:** Xử lý phần dư  để tìm ra  mục tiêu.
* **Chunk 4:** Tổng kết thuật toán và tối ưu thời gian.

Bạn đã sẵn sàng mổ xẻ vấn đề đầu tiên ở **Chunk 1** chưa?

---

### 📦 Chunk 1: Hiểu về "Khoảng cách" và "Số dư"

Hãy tưởng tượng bạn đang bước đi trên một con đường có các cột mốc cách đều nhau một khoảng là .

* Các cột mốc này là những số chia hết cho  (như ).
* Đề bài yêu cầu bạn tìm một điểm  gần vạch đích  nhất, nhưng điểm  này không được nằm ngay tại cột mốc, mà phải **vượt qua cột mốc đó một đoạn đúng bằng **.

**⚠️ Bẫy logic:** Nhiều bạn sẽ nghĩ chỉ cần lấy  rồi trừ đi một cái gì đó là ra ngay. Nhưng hãy cẩn thận, điểm  có thể nằm ở "chu kỳ" ngay trước  hoặc chính tại chu kỳ của .

❓ **Thử thách tư duy:**
Cho bộ dữ liệu: 
(Tức là: Tìm số  lớn nhất  sao cho  chia  dư ).

Đầu tiên, hãy thử với con số nhỏ hơn để nắm quy luật:
Nếu  và giới hạn .
**Theo bạn, số  lớn nhất thỏa mãn  và  là số nào?**

Hãy cho tôi biết đáp án của bạn và tại sao bạn chọn số đó nhé!

Chính xác! Với ,  và , số  lớn nhất thỏa mãn là **25**.

Tại sao lại là 25?

* Các "cột mốc" chia hết cho 10 gần đó là: 0, 10, 20, 30.
* Nếu ta chọn cột mốc **20** và cộng thêm dư **5**, ta được  (thỏa mãn ).
* Nếu ta chọn cột mốc **30** và cộng thêm dư **5**, ta được  (loại vì ).

---

### 🔍 Chunk 2: Tìm "Điểm tựa" gần n nhất

Để giải bài này một cách nhanh chóng với máy tính (nhất là khi  lên tới ), ta không thể dùng vòng lặp để thử từng số. Ta cần một công thức toán học.

Bước đầu tiên là tìm **cột mốc** (số chia hết cho ) ngay phía dưới hoặc bằng .
Trong lập trình, khi bạn thực hiện phép chia nguyên `n / x`, máy tính sẽ vứt bỏ phần thập phân.

**Ví dụ:** .
Nếu ta lấy kết quả đó nhân ngược lại cho : . Ta tìm được cột mốc gần nhất là **30**.

❓ **Thử thách tư duy:**
Quay lại ví dụ khó hơn một chút: .

1. Cột mốc chia hết cho  gần nhất (ngay phía dưới hoặc bằng ) là bao nhiêu? (Gợi ý: Tính `(n / x) * x`)
2. Nếu lấy cột mốc đó cộng thêm , kết quả có vượt quá  không?

Bạn hãy tính thử xem nhé! 🧮

Bạn tính toán rất nhanh! Nhưng hãy dừng lại một chút để kiểm tra lại con số này nhé. 🧐

Mục tiêu của chúng ta là tìm một số  sao cho  (với ).
Kết quả bạn vừa tính là  (tôi đoán bạn gõ nhầm một chút vì ).

Dù là  hay , hãy so sánh nó với "cột mốc" mà chúng ta có thể đạt được:

1. **Cột mốc gần nhất:** .
2. **Thử cộng dư:** Nếu ta lấy cột mốc này cộng thêm , ta được .
3. **Kiểm tra điều kiện:**  có nhỏ hơn hoặc bằng  không? Rõ ràng là **không** (nó lớn hơn  đơn vị).

Khi "cột mốc hiện tại + dư" vượt quá giới hạn , chúng ta buộc phải lùi lại một "chu kỳ" (một bước nhảy của ).

❓ **Thử thách tư duy:**
Nếu  đã quá xa, bạn hãy thử lấy số đó **trừ đi một khoảng ** (trong trường hợp này ).
Kết quả mới là bao nhiêu? Số đó có thỏa mãn chia  dư  và  không?

Bạn tính toán rất nhanh! Nhưng hãy dừng lại một chút để kiểm tra lại con số này nhé. 🧐

Mục tiêu của chúng ta là tìm một số  sao cho  (với ).
Kết quả bạn vừa tính là  (tôi đoán bạn gõ nhầm một chút vì ).

Dù là  hay , hãy so sánh nó với "cột mốc" mà chúng ta có thể đạt được:

1. **Cột mốc gần nhất:** .
2. **Thử cộng dư:** Nếu ta lấy cột mốc này cộng thêm , ta được .
3. **Kiểm tra điều kiện:**  có nhỏ hơn hoặc bằng  không? Rõ ràng là **không** (nó lớn hơn  đơn vị).

Khi "cột mốc hiện tại + dư" vượt quá giới hạn , chúng ta buộc phải lùi lại một "chu kỳ" (một bước nhảy của ).

❓ **Thử thách tư duy:**
Nếu  đã quá xa, bạn hãy thử lấy số đó **trừ đi một khoảng ** (trong trường hợp này ).
Kết quả mới là bao nhiêu? Số đó có thỏa mãn chia  dư  và  không?

Tuyệt vời! Bạn đã nắm bắt được hướng giải quyết rồi đấy. 🌟

Khi số  bị "lố" so với , việc lùi lại một khoảng  chính là cách để ta quay về cột mốc an toàn gần nhất mà vẫn giữ nguyên số dư .

Số  này thỏa mãn:

1.  (Hợp lệ ✅)
2.  (Hợp lệ ✅)

---

### 🛠️ Chunk 3: Xử lý "Bẫy" logic

Chúng ta vừa thấy có hai trường hợp xảy ra khi lấy `Cột mốc + y`:

* **Trường hợp A:** Kết quả  Đó chính là số  lớn nhất.
* **Trường hợp B:** Kết quả  Ta phải lùi lại  đơn vị ().

Bây giờ, hãy thử áp dụng tư duy này vào một trường hợp "nhạy cảm" hơn để xem thuật toán của chúng ta có bền bỉ không nhé.

❓ **Thử thách tư duy:**
Cho  và giới hạn .

1. Theo bạn, trong trường hợp này có tồn tại số  nào không? (Lưu ý: ).
2. Nếu áp dụng công thức: `Cột mốc = (4 / 10) * 10 = 0`, sau đó cộng . Kết quả là . Vì  nên ta lấy .
3. Số  có thỏa mãn điều kiện  không?

Trong lập trình, nếu kết quả ra số âm mà đề bài yêu cầu số không âm, ta phải xử lý thế nào? Bạn nghĩ sao về trường hợp này? 🤔

Trong lập trình thi đấu (Competitive Programming), chúng ta cần hết sức tỉnh táo với các điều kiện ràng buộc. Đề bài nói rằng . Nếu tính toán ra một số âm, điều đó có nghĩa là **không tồn tại** số  nào thỏa mãn yêu cầu trong phạm vi từ  đến .

Tuy nhiên, bạn hãy nhìn lại các ví dụ của Codeforces:  thường nhỏ, còn  có thể rất lớn. Trong hầu hết các test case của bài này, luôn có ít nhất một số  thỏa mãn (thậm chí  là một ứng cử viên nếu ).

---

### 🏁 Chunk 4: Tổng kết thuật toán

Chúng ta đã "mổ xẻ" xong các mảnh ghép logic. Bây giờ, hãy xâu chuỗi chúng lại thành một quy trình hoàn chỉnh để máy tính có thể hiểu được:

1. **Bước 1:** Tìm "cột mốc" chia hết cho  gần  nhất bằng cách: `moc = (n / x) * x`.
2. **Bước 2:** Thử tạo ra ứng cử viên  bằng cách: `k = moc + y`.
3. **Bước 3:** Kiểm tra xem  có vượt quá  không:
* Nếu : Chốt luôn đáp án là .
* Nếu : Lùi lại một bước sóng, đáp án là .



---

### 📝 Thử thách cuối cùng (Mã giả - Pseudocode)

Để biến tư duy này thành code, ta cần viết bằng tiếng Việt không dấu theo cấu trúc logic. Bạn hãy thử điền vào chỗ trống (...) để hoàn thiện thuật toán này nhé:

```text
Nhap x, y, n
Dat k = (n / x) * x + y

Neu k ... n:
    In ra k
Co nghia la (nguoc lai):
    In ra k - ...

```

**Bạn sẽ điền gì vào hai chỗ "..." trên để thuật toán chạy đúng hoàn toàn?** (Gợi ý: Hãy nhớ lại ví dụ  thì phải làm gì).

Chuẩn không cần chỉnh! Logic của chúng ta sẽ là:

1. **Nếu **: Đây chính là số lớn nhất thỏa mãn rồi, chúng ta giữ nguyên. ✅
2. **Nếu **: Nghĩa là chúng ta đã "nhảy" quá vạch đích, cần lùi lại đúng 1 chu kỳ  để quay về số  trước đó. 🔙

Vậy mã giả (pseudocode) hoàn chỉnh sẽ như thế này:

```text
Nhap x, y, n
Dat k = (n / x) * x + y

Neu k <= n:
    In ra k
Neu k > n:
    In ra k - x

```

---

### 🚀 Tối ưu hóa: Bạn có muốn thử thách thêm không?

Trong lập trình, đôi khi chúng ta muốn viết code ngắn gọn hơn nữa bằng cách gộp các điều kiện lại.

Thay vì dùng `if/else`, chúng ta có thể tính toán trực tiếp "phần dư hiện tại" của  so với  (gọi là ) để biết mình đang ở cách cột mốc bao xa, từ đó bù trừ số  vào.

Bạn có muốn tôi hướng dẫn cách viết công thức này chỉ trong **1 dòng duy nhất** không, hay bạn muốn dừng lại ở đây để tự mình chuyển mã giả kia thành code C++/Python? 💻