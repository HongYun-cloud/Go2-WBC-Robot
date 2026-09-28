#include <onnxruntime_cxx_api.h>

Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "Go2");
Ort::SessionOptions session_options;

Ort::Session session(
    env,
    "policy.onnx",
    session_options
);