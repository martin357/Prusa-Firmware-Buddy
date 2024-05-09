/**
 * @file screen_touch_error.cpp
 */
#include "screen_touch_error.hpp"

#include "ScreenHandler.hpp"
#include <hw/touchscreen/touchscreen.hpp>

ScreenTouchError::ScreenTouchError()
    : AddSuperWindow<screen_t>()
    , header(this, _("TOUCHSCREEN ERROR")) {}

void ScreenTouchError::windowEvent([[maybe_unused]] window_t *sender, [[maybe_unused]] GUI_event_t event, [[maybe_unused]] void *param) {
    if (event_in_progress) {
        return;
    }

    event_in_progress = true;

    touchscreen.set_enabled(false);
    MsgBoxWarning(_("Touch driver failed to initialize, touch functionality disabled"), Responses_Ok);
    Screens::Access()->Close();
}
