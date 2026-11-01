#pragma once

#include <optional>
#include <string_view>

#include <pl/Config.hpp>

namespace acecull {

struct AceConfig {
  int version = 1;
  bool cullEnabled = true;  // entity culling on/off
  bool heavy = false;       // heavy mode: culls at 60% of the distance
  int distance = 64;        // cull distance in blocks
  bool ramEnabled = true;   // RAM optimizer on/off
  int ramInterval = 30;     // seconds between memory purges
};

inline constexpr int kMinDistance = 16;
inline constexpr int kMaxDistance = 160;
inline constexpr int kMinRamInterval = 5;
inline constexpr int kMaxRamInterval = 120;

} // namespace acecull

namespace pl::config {

template <> struct Schema<acecull::AceConfig> {
  static constexpr std::string_view title = "Ace Cull";
  static constexpr std::string_view description =
      "Entity culling and RAM optimizer for Minecraft Bedrock 1.26.60.";

  static constexpr FieldSchema field(std::string_view name) {
    if (name == "version") {
      return {"Version", "Config schema version managed by the mod.",
              std::nullopt, std::nullopt, true};
    }
    if (name == "cullEnabled") {
      return {"Entity Cull", "Skip drawing entities beyond the cull distance.",
              std::nullopt, std::nullopt, false};
    }
    if (name == "heavy") {
      return {"Heavy Culling",
              "Cull at 60% of the distance for a bigger FPS gain.",
              std::nullopt, std::nullopt, false};
    }
    if (name == "distance") {
      return {"Cull Distance", "Entities farther than this (blocks) are skipped.",
              acecull::kMinDistance, acecull::kMaxDistance, false};
    }
    if (name == "ramEnabled") {
      return {"RAM Optimizer", "Periodically return unused memory to Android.",
              std::nullopt, std::nullopt, false};
    }
    if (name == "ramInterval") {
      return {"RAM Interval", "Seconds between memory purges.",
              acecull::kMinRamInterval, acecull::kMaxRamInterval, false};
    }
    return {};
  }
};

} // namespace pl::config
