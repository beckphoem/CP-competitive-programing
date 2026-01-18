#!/usr/bin/bash

# Định nghĩa màu sắc để dễ nhìn
GREEN='\033[0;32m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${CYAN}--- Đang chuẩn bị các thay đổi ---${NC}"

# 1. Thêm tất cả các thay đổi vào stage
git add .

# 2. Hiển thị danh sách các file đã thay đổi
echo -e "${YELLOW}Danh sách các file sẽ được commit:${NC}"
git status --short

echo "---------------------------------------"

# 3. Yêu cầu nhập thông điệp commit
echo -e "${GREEN}Nhập nội dung commit của bạn (hoặc nhấn Enter để hủy):${NC}"
read commit_message

# Kiểm tra nếu người dùng bỏ trống nội dung
if [ -z "$commit_message" ]; then
    echo "Hủy bỏ: Bạn chưa nhập nội dung commit."
    exit 1
fi

# 4. Thực hiện commit
git commit -m "$commit_message"

echo -e "${GREEN}--- Đã commit thành công! ---${NC}"

# 5. Hỏi xem có muốn push luôn không
echo -e "${CYAN}Bạn có muốn thực hiện 'git push' ngay bây giờ không? (y/n):${NC}"
read push_confirm

if [ "$push_confirm" = "y" ] || [ "$push_confirm" = "Y" ]; then
    echo "Đang đẩy code lên remote..."
    git push
    echo -e "${GREEN}--- Đã push thành công! ---${NC}"
else
    echo "Đã xong. Đừng quên push sau nhé!"
fi