Chào bạn! Tôi đã nắm rõ vai trò là **Huấn luyện viên Tư duy Thuật toán** của bạn. Chúng ta sẽ cùng nhau "mổ xẻ" các bài toán theo phong cách **Micro-Chunks**, tập trung hoàn toàn vào chiến thuật và logic thay vì chỉ nhìn vào code. 🧠

Hãy bắt đầu với bài **Codeforces 1328A - Divisibility Problem**.

---

## 🏗️ Bước 1: Tiếp nhận & Phẫu thuật (Briefing)

**Tóm tắt đề bài bằng "ngôn ngữ con người":**
Bạn có hai số nguyên dương  và . Nhiệm vụ của bạn là tìm số bước **tối thiểu** để biến  thành một số chia hết cho .

* **Quy tắc:** Trong mỗi bước, bạn chỉ được phép tăng  lên 1 đơn vị ().
* **Mục tiêu:** Tìm số bước tăng ít nhất sao cho .

**Lộ trình tư duy của chúng ta:**

1. **Chunk 1:** Hiểu về bản chất của phép chia hết và "khoảng cách" tới mục tiêu.
2. **Chunk 2:** Xử lý trường hợp đặc biệt (Khi  đã "về đích" sẵn).
3. **Chunk 3:** Tối ưu hóa - Tại sao không nên dùng vòng lặp?

Bạn đã sẵn sàng mổ xẻ vấn đề đầu tiên chưa? 🍏

---

## 🧩 Chunk 1: Khoảng cách tới "vạch đích"

Hãy tưởng tượng số  giống như **độ dài của một bước chân**. Bạn đang ở vị trí  và muốn nhảy đến một vị trí là bội số của  (ví dụ: ).

Nếu bạn chưa đứng ngay tại một bội số của , bạn phải "bước rón rén" từng bước 1 đơn vị để tiến tới cái mốc tiếp theo chia hết cho .

❓ **Thử thách tư duy:**
Nếu  và .

1. Các mốc chia hết cho  gần đó là: 
2. Vì bạn chỉ có thể **tăng** , mốc tiếp theo mà  có thể chạm tới là bao nhiêu?
3. Bạn cần thực hiện bao nhiêu bước tăng (mỗi bước +1) để từ  chạm được mốc đó?

Hãy đưa ra con số và cách bạn nhẩm tính nhé! 🏃‍♂️

Đúng rồi! Với  và , bội số tiếp theo của 4 mà lớn hơn 13 chính là **16**. Để đi từ 13 đến 16, chúng ta cần  bước.

*(Lưu ý nhỏ: 15 không chia hết cho 4, nên "vạch đích" phải là 16 bạn nhé!)* 🏁

Bây giờ, hãy nâng cấp tư duy lên một chút để tìm ra công thức tổng quát, thay vì phải đếm thủ công.

---

## 🧩 Chunk 2: Công thức "Nhảy cóc"

Trong lập trình thi đấu, nếu  và  rất lớn (ví dụ ), chúng ta không thể dùng vòng lặp `while (a % b != 0) a++;` vì sẽ bị quá thời gian (TLE). Ta cần một phép tính ra ngay kết quả.

Hãy nhìn lại ví dụ :

1. Phép chia nguyên:  (dư 1). Điều này nghĩa là  đã vượt qua mốc .
2. Mốc tiếp theo ta cần đến là .

**Tổng quát hóa:**
Nếu ta lấy  chia cho :

* Phần nguyên là .
* Số dư là .

❓ **Thử thách tư duy:**
Dựa vào số dư , bạn làm thế nào để biết cần thêm bao nhiêu đơn vị nữa để  chạm đến mốc chia hết tiếp theo?

*Gợi ý: Nếu bạn có 13 cái kẹo (), muốn chia đều vào các túi mỗi túi 4 cái (). Bạn đang dư ra 1 cái (). Bạn cần mua thêm bao nhiêu cái nữa để đóng được một túi hoàn chỉnh tiếp theo?*

Chính xác! 🎯 Công thức  chính là số bước ít nhất để bạn "bù" thêm vào  sao cho nó chạm đến bội số tiếp theo của .

Hãy nhìn lại ví dụ: .

*  (số dư hiện tại).
* Số bước cần thêm:  bước.
* Kết quả:  (chia hết cho 4). Đúng như bạn đã tính! ✅

Tuy nhiên, có một **"cái bẫy"** nhỏ trong lập trình khi dùng công thức này.

---

## 🧩 Chunk 3: Xử lý "Bẫy" logic

Giả sử quả dưa hấu hoặc con số  của chúng ta **đã chia hết cho  ngay từ đầu**.
Ví dụ: .

1. .
2. Nếu áp dụng công thức , ta sẽ có:  bước.
3. Nhưng thực tế, nếu  đã chia hết cho , chúng ta cần **0** bước.

❓ **Thử thách tư duy:**
Theo bạn, làm thế nào để sửa công thức hoặc dùng điều kiện gì để khi , kết quả trả về đúng là **0** thay vì là ?

*(Gợi ý: Bạn có thể dùng một câu lệnh điều kiện `if` hoặc một mẹo nhỏ với phép chia dư `%` một lần nữa).*

Chính xác! 🎯 Việc sử dụng câu lệnh điều kiện `if (a % b != 0)` là một cách rất rõ ràng để tách biệt hai tình huống:

1. **Trường hợp 1:**  đã chia hết cho   Kết quả là .
2. **Trường hợp 2:**  chưa chia hết cho   Kết quả là .

Ngoài cách dùng `if`, trong lập trình thi đấu còn có một "mẹo" dùng toán học để gộp cả hai trường hợp vào một dòng công thức duy nhất mà không cần kiểm tra điều kiện.

---

## 🧩 Chunk 4: Tổng kết thuật toán

Trước khi chúng ta chốt lại bằng mã giả, hãy thử kiểm tra xem bạn có nắm được quy luật tổng quát không nhé.

Ta có công thức: `(b - (a % b)) % b`

❓ **Thử thách tư duy:**
Hãy thử áp dụng công thức "một dòng" này vào 2 ví dụ sau và cho biết kết quả:

1. Với : `(4 - (13 % 4)) % 4` bằng bao nhiêu?
2. Với : `(4 - (8 % 4)) % 4` bằng bao nhiêu?

Công thức này có giúp chúng ta giải quyết được cái bẫy "số dư bằng 0" mà không cần dùng lệnh `if` không? 🤔

Tuyệt vời! Bạn đã tính toán rất chuẩn:

1. Với : `(4 - (13 % 4)) % 4`  `(4 - 1) % 4`  `3 % 4` = **3**.
2. Với : `(4 - (8 % 4)) % 4`  `(4 - 0) % 4`  `4 % 4` = **0**.

Phép `% b` ở ngoài cùng chính là "cú chốt" để biến kết quả  thành  khi  đã chia hết cho . Cách này giúp code của bạn ngắn gọn và cực kỳ tối ưu vì không cần dùng tới `if/else`. 🚀

---

## 🏁 Bước cuối: Chốt thuật toán

Chúng ta đã đi qua toàn bộ tư duy của bài toán. Đây là bản tóm tắt chiến thuật (Mã giả):

> **Nhap** so luong test case .
> **Lap**  lan:
> **Nhap** hai so  va .
> **Neu** : **In ra** 0.
> **Neu khong**: **In ra** .
> *(Hoac dung cong thuc mot dong: `(b - (a % b)) % b`)*.

**Ghi chú về Edge Case:** Trong bài này, đề bài cho , nên chúng ta không cần lo lắng về trường hợp chia cho 0. Tuy nhiên, hãy luôn nhớ kiểm tra kiểu dữ liệu (với  thì kiểu `int` trong C++ vẫn chịu được, nhưng nếu lớn hơn phải dùng `long long`).

Bạn đã thấy tự tin để tự mình viết code cho bài này chưa? Hay bạn muốn tôi thử thách thêm một bài toán khác có tư duy tương tự nhưng lắt léo hơn một chút? 😊