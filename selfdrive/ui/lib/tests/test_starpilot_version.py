from openpilot.selfdrive.ui.lib.starpilot_version import (
  DEFAULT_HOME_SCREEN_NAME,
  HOME_SCREEN_NAME_MAX_LENGTH,
  home_screen_name,
  normalize_home_screen_name,
)


def test_home_screen_name_defaults_and_truncates():
  assert normalize_home_screen_name("") == DEFAULT_HOME_SCREEN_NAME
  assert normalize_home_screen_name("  Custom Name  ") == "Custom Name"
  assert len(normalize_home_screen_name("abcdefghijklmnop")) == HOME_SCREEN_NAME_MAX_LENGTH


class _UnknownKey(Exception):
  pass


class _OldBuildParams:
  """Mimics on-device params_pyx without the HomeScreenName key."""

  def get(self, *args, **kwargs):
    raise _UnknownKey(b"HomeScreenName")

  def get_default_value(self, *args, **kwargs):
    raise _UnknownKey(b"HomeScreenName")


def test_home_screen_name_survives_unknown_key():
  assert home_screen_name(_OldBuildParams()) == DEFAULT_HOME_SCREEN_NAME
