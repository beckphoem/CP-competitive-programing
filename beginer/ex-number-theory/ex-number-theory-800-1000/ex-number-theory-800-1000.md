Dưới đây là toàn bộ nội dung báo cáo nghiên cứu về các bài tập lý thuyết số trên Codeforces trong dải rating 800-1000, bao gồm đề bài tiếng Việt và hướng giải quyết chi tiết:

# Chiến lược Phát triển Tư duy Số học qua Hệ thống Bài tập Codeforces Rating 800-1000

Việc nắm vững lý thuyết số cơ bản là cột mốc quan trọng đối với lập trình viên thi đấu. Ở mức rating 800-1000, các bài tập yêu cầu khả năng phân tích toán học sơ cấp, nhận diện quy luật và tối ưu hóa thuật toán thay vì chỉ lập trình thuần túy.

## Tuyển tập 10 Bài tập Lý thuyết Số tiêu biểu

### 1. 1328A - Divisibility Problem (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1328/A](https://codeforces.com/problemset/problem/1328/A)
* **Đề bài**: Cho hai số nguyên dương  và . Tìm số bước tối thiểu để  trở thành một số chia hết cho , mỗi bước bạn có thể tăng  thêm 1 đơn vị.
* **Hướng giải quyết**: Thay vì dùng vòng lặp (gây quá thời gian), ta sử dụng phép chia dư. Nếu , kết quả là 0. Ngược lại, số bước cần thiết là .

### 2. 1370A - Maximum GCD (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1370/A](https://codeforces.com/problemset/problem/1370/A)
* **Đề bài**: Cho số nguyên . Tìm giá trị lớn nhất của  với .
* **Hướng giải quyết**: Để , thì  và  phải là bội của . Cặp bội nhỏ nhất là  và . Điều kiện  dẫn đến . Đáp án tối ưu là .

### 3. 1325A - EhAb AnD gCd (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1325/A](https://codeforces.com/problemset/problem/1325/A)
* **Đề bài**: Cho số nguyên dương . Tìm bất kỳ cặp số  sao cho .
* **Hướng giải quyết**: Sử dụng tính chất của số 1:  và . Với , ta luôn có cặp  thỏa mãn phương trình .

### 4. 1374A - Required Remainder (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1374/A](https://codeforces.com/problemset/problem/1374/A)
* **Đề bài**: Cho . Tìm số  lớn nhất sao cho  và .
* **Hướng giải quyết**: Sử dụng công thức trực tiếp: . Công thức này đảm bảo tìm được bội số của  phù hợp nhất mà khi cộng thêm  vẫn không vượt quá .

### 5. 1633A - Div. 7 (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1633/A](https://codeforces.com/problemset/problem/1633/A)
* **Đề bài**: Thay đổi ít nhất các chữ số của  (2-3 chữ số) để số mới chia hết cho 7 và không có số 0 ở đầu.
* **Hướng giải quyết**: Kiểm tra nếu  đã chia hết cho 7. Nếu chưa, thử thay đổi chữ số hàng đơn vị của  từ  đến . Trong một dải 10 số liên tiếp, luôn có ít nhất một số chia hết cho 7.



### 6. 1088A - Ehab and another construction problem (Rating 800)

* **Link**: [https://codeforces.com/problemset/problem/1088/A](https://codeforces.com/problemset/problem/1088/A)
* **Đề bài**: Tìm  sao cho  chia hết cho , , và .
* **Hướng giải quyết**: Với , ta có thể chọn đơn giản  và  (nếu  chia hết cho ,  và ). Một lựa chọn an toàn khác là cặp  cho hầu hết các trường hợp .



### 7. 1343A - Candies (Rating 900)

* **Link**: [https://codeforces.com/problemset/problem/1343/A](https://codeforces.com/problemset/problem/1343/A)
* **Đề bài**: Tổng số kẹo mua trong  ngày () là . Ngày 1 mua , các ngày sau mua gấp đôi ngày trước. Tìm  nguyên dương.
* **Hướng giải quyết**: Tổng kẹo là . Ta duyệt  từ  đến , nếu  chia hết cho  thì  là đáp án cần tìm.

### 8. 1475B - New Year's Number (Rating 900)

* **Link**:([https://codeforces.com/problemset/problem/1475/B](https://codeforces.com/problemset/problem/1475/B))
* **Đề bài**: Kiểm tra  có thể biểu diễn thành tổng của các số 2020 và 2021 không.
* **Hướng giải quyết**: Giải phương trình . Đặt , ta có  và . Điều kiện để tồn tại  là .

### 9. 1474B - Different Divisors (Rating 1000)

* **Link**:([https://codeforces.com/problemset/problem/1474/B](https://codeforces.com/problemset/problem/1474/B))
* **Đề bài**: Cho . Tìm số  nhỏ nhất có ít nhất 4 ước sao cho khoảng cách giữa 2 ước bất kỳ ít nhất là .
* **Hướng giải quyết**: Ước đầu tiên là 1. Ta cần tìm số nguyên tố  và số nguyên tố . Khi đó số  sẽ là số nhỏ nhất thỏa mãn yêu cầu.

### 10. 1203C - Common Divisors (Rating 1000)

* **Link**: [https://codeforces.com/problemset/problem/1203/C](https://codeforces.com/problemset/problem/1203/C)
* **Đề bài**: Tìm số lượng ước chung của tất cả các phần tử trong mảng .
* **Hướng giải quyết**: Tìm ước chung lớn nhất (GCD) của cả mảng. Sau đó, đếm số lượng ước của giá trị GCD này bằng cách duyệt đến căn bậc hai của nó.



## Lộ trình và Kỹ thuật Tối ưu

* **Sử dụng kiểu dữ liệu phù hợp**: Với các bài toán có giá trị đến , bắt buộc sử dụng `long long` trong C++ để tránh tràn số.


* **Độ phức tạp**: Ưu tiên các giải pháp  hoặc . Các bài toán đếm ước thường đạt mức .


* **Luyện tập**: Nên giải ít nhất 15-20 bài tập thuộc chủ đề này mỗi tuần để tăng tốc độ nhận diện quy luật.


* **Ghi chú sai lầm**: Duy trì "Nhật ký lỗi" để ghi lại các trường hợp tràn số hoặc sai số thực (`double`) khi xử lý số học.