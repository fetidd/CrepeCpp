export module Error;

import std;

export enum class ErrorCode {
    UNKNOWN = 0,
    FILE_NOT_FOUND,
    INVALID_ARGUMENT,
};

export class ErrorType {
public:
    std::string message;
    ErrorCode code() const { return code_; };
protected:
    ErrorCode code_{ ErrorCode::UNKNOWN };
};

export class FileNotFound : public ErrorType {
public:
    FileNotFound(std::string file_path) {
        message = std::format("File {} not found!", file_path);
        code_ = ErrorCode::FILE_NOT_FOUND;
    };
};

export class InvalidArgument : public ErrorType {
public:
    InvalidArgument() {
        message = "Invalid argument";
        code_ = ErrorCode::INVALID_ARGUMENT;
    }
};

export bool operator== (const ErrorType& lhs, const ErrorType& rhs) { return lhs.code() == rhs.code(); }

export template <typename Exp> using Result = std::expected<Exp, ErrorType>;