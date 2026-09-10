"""Host-safe consistency check for the como-heavy brand atlas.

Stdlib only: validates the .fnt metrics against the .png dimensions so a
regenerated atlas can never again ship a mismatch that kills UI startup.
Run directly: python3 test_como_heavy_atlas.py (no pytest/pyray needed).
"""

import re
import struct
from pathlib import Path

FONT_DIR = Path(__file__).resolve().parent
FNT_PATH = FONT_DIR / "como-heavy.fnt"
PNG_PATH = FONT_DIR / "como-heavy.png"


def _png_size(path: Path) -> tuple[int, int]:
  with path.open("rb") as f:
    header = f.read(33)
  assert header[:8] == b"\x89PNG\r\n\x1a\n", "not a PNG file"
  width, height = struct.unpack(">II", header[16:24])
  return width, height


def test_como_heavy_atlas_is_consistent():
  lines = FNT_PATH.read_text().splitlines()
  header = lines[1]
  match = re.search(r"scaleW=(\d+)\s+scaleH=(\d+)", header)
  assert match, f"unparseable fnt header: {header}"
  scale_w, scale_h = int(match.group(1)), int(match.group(2))

  png_w, png_h = _png_size(PNG_PATH)
  assert (scale_w, scale_h) == (png_w, png_h), f"fnt declares {scale_w}x{scale_h} but png is {png_w}x{png_h}"

  entries = [line for line in lines if line.startswith("char id=")]
  count_match = re.search(r"chars count=(\d+)", "\n".join(lines[:5]))
  assert count_match and int(count_match.group(1)) == len(entries), "fnt header count does not match char entries"

  seen: set[int] = set()
  for entry in entries:
    fields = dict(re.findall(r"(\w+)=(-?\d+)", entry))
    glyph_id = int(fields["id"])
    assert 32 <= glyph_id <= 126, f"glyph {glyph_id} outside brand ASCII range"
    assert glyph_id not in seen, f"duplicate glyph {glyph_id}"
    seen.add(glyph_id)
    x, y, w, h = (int(fields[k]) for k in ("x", "y", "width", "height"))
    assert x >= 0 and y >= 0 and x + w <= png_w and y + h <= png_h, f"glyph {glyph_id} rect out of atlas bounds"

  assert len(seen) == 95, f"expected full ASCII 32..126 atlas, got {len(seen)} glyphs"


if __name__ == "__main__":
  test_como_heavy_atlas_is_consistent()
  print("como-heavy atlas OK")
